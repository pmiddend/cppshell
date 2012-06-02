#ifndef CPPSHELL_COMMAND_OUTPUT_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define CPPSHELL_COMMAND_OUTPUT_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <cppshell/command_output/object_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>

namespace cppshell
{
namespace command_output
{
typedef
fcppt::scoped_ptr<cppshell::command_output::object>
object_scoped_ptr;
}
}

#endif

