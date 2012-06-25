#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/exception.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/linux/eventfd.hpp>
#include <cppshell/output/thread_data.hpp>
#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <functional>
#include <unistd.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


cppshell::output::thread_data::thread_data(
	cppshell::output::redirection_target const &_redirection_target,
	cppshell::linux::eventfd const &_cancel_fd)
:
	epoll_object_{
		cppshell::linux::epoll::parallel_event_count{
			1024}},
	asynchronous_output_thread_{
		std::bind(
			&cppshell::output::thread_data::asynchronous_output_thread,
			this,
			_redirection_target,
			std::cref(
				_cancel_fd))}
{
	epoll_object_.add(
		_cancel_fd.fd(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

void
cppshell::output::thread_data::add(
	cppshell::strong_fd_unique_ptr _asynchronous_fd)
{
	_asynchronous_fd->dont_close();

	epoll_object_.add(
		_asynchronous_fd->value(),
		cppshell::linux::epoll::control_flags_field{
			cppshell::linux::epoll::control_flags::is_readable});
}

cppshell::output::thread_data::~thread_data()
{
	asynchronous_output_thread_.join();
}

void
cppshell::output::thread_data::asynchronous_output_thread(
	cppshell::output::redirection_target const &_redirection_target,
	cppshell::linux::eventfd const &_cancel_fd)
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
			if(fd.get() == _cancel_fd.fd().get())
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

			ssize_t const bytes_written{
				::write(
					_redirection_target.get().get(),
					buffer.data(),
					static_cast<std::size_t>(
						bytes_read))};

			if(bytes_written != bytes_read)
				throw
					cppshell::exception{
						"Couldn't redirect all bytes at once. Read "+
						fcppt::insert_to_std_string(
							bytes_read)+
						" bytes but wrote "+
						fcppt::insert_to_std_string(
							bytes_written)};
		}
	}
}
