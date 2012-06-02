#ifndef CPPSHELL_STREAM_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_STREAM_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <cppshell/stream/object_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace cppshell
{
namespace stream
{
typedef
fcppt::unique_ptr<cppshell::stream::object>
object_unique_ptr;
}
}

#endif

