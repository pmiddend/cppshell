#ifndef CPPSHELL_LINUX_EPOLL_CALLBACK_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_CALLBACK_HPP_INCLUDED

#include <cppshell/linux/epoll/callback_fn.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
std::function<cppshell::linux::epoll::callback_fn>
callback;
}
}
}

#endif

