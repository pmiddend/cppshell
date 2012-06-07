#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/linux/epoll/object.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <iostream>
#include <vector>
#include <fcppt/config/external_end.hpp>


cppshell::linux::epoll::object::object(
	cppshell::linux::epoll::parallel_event_count const &_parallel_event_count)
:
	fd_{
		::epoll_create(
			_parallel_event_count.get())},
	parallel_event_count_{
		_parallel_event_count}
{
	cppshell::check_unix_command_error(
		"epoll_create",
		fd_.get());
}

cppshell::linux::epoll::object::object(
	object &&_other)
:
	fd_{
		_other.fd_},
	parallel_event_count_{
		_other.parallel_event_count_}
{
}

cppshell::linux::epoll::fd_set const
cppshell::linux::epoll::object::wait(
	cppshell::linux::epoll::optional_timeout_duration const &_timeout)
{
	typedef
	std::vector<struct epoll_event>
	raw_event_array;

	raw_event_array returned_events{
		static_cast<raw_event_array::size_type>(
			parallel_event_count_.get())};

	int number_of_returned_fds =
		::epoll_wait(
			fd_.get(),
			returned_events.data(),
			parallel_event_count_.get(),
			_timeout
			?
				static_cast<int>(
					_timeout->count())
			:
				-1);

	cppshell::check_unix_command_error(
		"epoll_wait",
		number_of_returned_fds);

	cppshell::linux::epoll::fd_set result;

	for(
		raw_event_array::const_iterator e =
			returned_events.begin();
		e != std::next(returned_events.begin(),number_of_returned_fds);
		++e)
		result.insert(
			cppshell::posix::fd{
				e->data.fd});

	return
		result;
}

void
cppshell::linux::epoll::object::add(
	cppshell::posix::fd const &_fd,
	cppshell::linux::epoll::control_flags_field const &_control_flags)
{
	struct epoll_event e;

	e.events = 0;

	if(_control_flags & cppshell::linux::epoll::control_flags::is_readable)
		e.events |= EPOLLIN;

	if(_control_flags & cppshell::linux::epoll::control_flags::is_writeable)
		e.events |= EPOLLOUT;

	e.data.fd =
		_fd.get();

	cppshell::check_unix_command_error(
		"epoll_ctl",
		::epoll_ctl(
			fd_.get(),
			EPOLL_CTL_ADD,
			_fd.get(),
			&e));
}

cppshell::linux::epoll::object::~object()
{
}
