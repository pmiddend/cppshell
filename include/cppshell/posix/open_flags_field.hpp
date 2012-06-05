#ifndef CPPSHELL_POSIX_OPEN_FLAGS_FIELD_HPP_INCLUDED
#define CPPSHELL_POSIX_OPEN_FLAGS_FIELD_HPP_INCLUDED

#include <cppshell/posix/open_flags.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>

namespace cppshell
{
namespace posix
{
typedef
fcppt::container::bitfield::object
<
	cppshell::posix::open_flags::type,
	cppshell::posix::open_flags::size
>
open_flags_field;
}
}

#endif

