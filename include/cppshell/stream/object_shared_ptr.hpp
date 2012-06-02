#ifndef CPPSHELL_STREAM_OBJECT_SHARED_PTR_HPP_INCLUDED
#define CPPSHELL_STREAM_OBJECT_SHARED_PTR_HPP_INCLUDED

#include <cppshell/stream/object_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace cppshell
{
namespace stream
{
typedef
fcppt::shared_ptr<cppshell::stream::object>
object_shared_ptr;
}
}

#endif

