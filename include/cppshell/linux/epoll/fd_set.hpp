#ifndef CPPSHELL_LINUX_EPOLL_FD_SET_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_FD_SET_HPP_INCLUDED

#include <cppshell/posix/fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
std::set<cppshell::posix::fd>
fd_set;
}
}
}

#endif

