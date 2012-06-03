#ifndef CPPSHELL_LINUX_EPOLL_PARALLEL_EVENT_COUNT_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_PARALLEL_EVENT_COUNT_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>

namespace cppshell
{
namespace linux
{
namespace epoll
{
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	parallel_event_count);
}
}
}

#endif

