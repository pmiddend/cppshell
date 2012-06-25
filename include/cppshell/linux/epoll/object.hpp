#ifndef CPPSHELL_LINUX_EPOLL_OBJECT_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_OBJECT_HPP_INCLUDED

#include <cppshell/noncopyable.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/linux/epoll/control_flags_field.hpp>
#include <cppshell/linux/epoll/fd_set.hpp>
#include <cppshell/linux/epoll/optional_timeout_duration.hpp>
#include <cppshell/linux/epoll/parallel_event_count.hpp>
#include <cppshell/posix/fd.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace linux
{
namespace epoll
{
class object
{
CPPSHELL_NONCOPYABLE(
	object);
public:
	CPPSHELL_SYMBOL
	explicit
	object(
		cppshell::linux::epoll::parallel_event_count const &);

	CPPSHELL_SYMBOL
	cppshell::linux::epoll::fd_set const
	wait(
		cppshell::linux::epoll::optional_timeout_duration const &);

	CPPSHELL_SYMBOL
	void
	add(
		cppshell::posix::fd const &,
		cppshell::linux::epoll::control_flags_field const &);

	CPPSHELL_SYMBOL
	~object();
private:
	cppshell::posix::fd fd_;
	cppshell::linux::epoll::parallel_event_count const parallel_event_count_;
};
}
}
}

#endif

