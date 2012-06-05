#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/context.hpp>
#include <cppshell/posix/wait_for_process.hpp>
#include <cppshell/stream/object.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::context::context(
	cppshell::process::wait_for_completion const &_wait_for_completion)
:
	process_manager_{
		_wait_for_completion},
	cancel_event_{
		static_cast<cppshell::linux::eventfd::initial_value_type>(
			0)},
	epoll_object_{
		cppshell::linux::epoll::parallel_event_count{
			1024}},
	asynchronous_output_thread_{
		std::bind(
			&context::asynchronous_output_thread,
			this)}
{
	epoll_object_.add(
		cancel_event_.fd(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

cppshell::process::manager &
cppshell::context::process_manager()
{
	return
		process_manager_;
}

cppshell::process::manager const &
cppshell::context::process_manager() const
{
	return
		process_manager_;
}

void
cppshell::context::add_asynchronous_output(
	cppshell::stream::object_unique_ptr _asynchronous_stream)
{
	_asynchronous_stream->dont_close_on_destruction();

	epoll_object_.add(
		_asynchronous_stream->fd(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

cppshell::context::~context()
{
	cancel_event_.add(
		1u);

	asynchronous_output_thread_.join();
}

void
cppshell::context::asynchronous_output_thread()
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
