#ifndef CPPSHELL_LINUX_EPOLL_TIMEOUT_DURATION_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_TIMEOUT_DURATION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
std::chrono::milliseconds
timeout_duration;
}
}
}

#endif

