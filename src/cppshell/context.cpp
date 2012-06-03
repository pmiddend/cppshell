#include <array>
#include <cppshell/check_unix_command_error.hpp>
#include <unistd.h>
#include <cppshell/context.hpp>
#include <cppshell/stream/object.hpp>
#include <cppshell/posix/wait_for_process.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <iostream>
#include <fcppt/config/external_end.hpp>
#include <fcppt/container/bitfield/object.hpp>


cppshell::context::context()
:
	processes_{},
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

void
cppshell::context::add_process(
	cppshell::posix::process_id const &_process_id,
	cppshell::optional_process_description const &_process_description)
{
	processes_.push_back(
		process_tuple{
			_process_id,
			_process_description});
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

void
cppshell::context::wait_for_processes()
{
	for(
		cppshell::context::process_tuple const &current_tuple : processes_)
	{
		if(
			cppshell::posix::wait_for_process(
				std::get<cppshell::context::process_id_index>(
					current_tuple)).get())
		{
			std::string const process_description{
				std::get<process_description_index>(
					current_tuple)
				?
					*std::get<process_description_index>(
						current_tuple)
				:
					std::string{
						"<unknown id>"}};

			std::cerr
				<< "Process \""
				<< process_description
				<< "\" failed!\n";
		}
	}

	processes_.clear();
}

cppshell::context::~context()
{
	cancel_event_.add(
		1u);

	asynchronous_output_thread_.join();

	this->wait_for_processes();
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
