#ifndef CPPSHELL_LINUX_EPOLL_CONTROL_FLAGS_FIELD_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_CONTROL_FLAGS_FIELD_HPP_INCLUDED

#include <cppshell/linux/epoll/control_flags.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>

namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
fcppt::container::bitfield::object
<
	cppshell::linux::epoll::control_flags::type,
	cppshell::linux::epoll::control_flags::size
>
control_flags_field;
}
}
}

#endif

