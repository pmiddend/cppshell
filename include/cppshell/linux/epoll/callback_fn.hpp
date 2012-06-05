#ifndef CPPSHELL_LINUX_EPOLL_CALLBACK_FN_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_CALLBACK_FN_HPP_INCLUDED

#include <cppshell/posix/fd.hpp>

namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
void
callback_fn(
	cppshell::posix::fd const &);
}
}
}

#endif

