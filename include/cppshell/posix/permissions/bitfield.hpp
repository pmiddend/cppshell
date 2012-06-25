#ifndef CPPSHELL_POSIX_PERMISSIONS_BITFIELD_HPP_INCLUDED
#define CPPSHELL_POSIX_PERMISSIONS_BITFIELD_HPP_INCLUDED

#include <cppshell/posix/permissions/underlying_enum.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>

namespace cppshell
{
namespace posix
{
namespace permissions
{
typedef
fcppt::container::bitfield::object
<
	cppshell::posix::permissions::underlying_enum::type,
	cppshell::posix::permissions::underlying_enum::size
>
bitfield;
}
}
}

#endif

