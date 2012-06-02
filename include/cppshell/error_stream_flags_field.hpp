#ifndef CPPSHELL_ERROR_STREAM_FLAGS_FIELD_HPP_INCLUDED
#define CPPSHELL_ERROR_STREAM_FLAGS_FIELD_HPP_INCLUDED

#include <cppshell/error_stream_flags.hpp>
#include <fcppt/container/bitfield/object_fwd.hpp>

namespace cppshell
{
typedef
fcppt::container::bitfield::object
<
	cppshell::error_stream_flags::type,
	cppshell::error_stream_flags::size
>
error_stream_flags_field;
}

#endif

