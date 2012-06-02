#ifndef CPPSHELL_STREAM_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define CPPSHELL_STREAM_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <cppshell/stream/object_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>

namespace cppshell
{
namespace stream
{
typedef
fcppt::scoped_ptr<cppshell::stream::object>
object_scoped_ptr;
}
}

#endif

