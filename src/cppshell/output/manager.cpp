#include <cppshell/strong_fd.hpp>
#include <cppshell/check_unix_command_error.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <cppshell/output/manager.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::output::manager::manager()
:
	cancel_event_{
		static_cast<cppshell::linux::eventfd::initial_value_type>(
			0)},
	epoll_object_{
		cppshell::linux::epoll::parallel_event_count{
			1024}},
	asynchronous_output_thread_{
		std::bind(
			&cppshell::output::manager::asynchronous_output_thread,
			this)}
{
	epoll_object_.add(
		cancel_event_.fd(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

void
cppshell::output::manager::add_asynchronous_output(
	cppshell::strong_fd_unique_ptr _asynchronous_fd)
{
	_asynchronous_fd->dont_close();

	epoll_object_.add(
		_asynchronous_fd->value(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

cppshell::output::manager::~manager()
{
	cancel_event_.add(
		1u);

	asynchronous_output_thread_.join();
}

void
cppshell::output::manager::asynchronous_output_thread()
{
	bool cancel_triggered{
		false};

	std::size_t const block_size{
		1024u};

	std::array<char,block_size> buffer;

	while(!cancel_triggered)
	{
		for(
			cppshell::posix::fd const &fd :
				epoll_object_.wait(
					cppshell::linux::epoll::optional_timeout_duration{}))
		{
			if(fd.get() == cancel_event_.fd().get())
			{
				cancel_triggered = true;
				break;
			}

			ssize_t const bytes_read{
				::read(
					fd.get(),
					buffer.data(),
					buffer.size())};

			cppshell::check_unix_command_error(
				"read",
				static_cast<int>(
					bytes_read));

			if(bytes_read == 0)
				continue;

			std::cerr.write(
				buffer.data(),
				static_cast<std::streamsize>(
					bytes_read));
		}
	}
}
