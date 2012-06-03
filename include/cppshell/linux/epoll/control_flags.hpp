#ifndef CPPSHELL_LINUX_EPOLL_CONTROL_FLAGS_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_CONTROL_FLAGS_HPP_INCLUDED

namespace cppshell
{
namespace linux
{
namespace epoll
{
namespace control_flags
{
enum type
{
	is_readable,
	is_writeable,
	size
};
}
}
}
}

#endif

