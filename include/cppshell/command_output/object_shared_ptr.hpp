#ifndef CPPSHELL_COMMAND_OUTPUT_OBJECT_SHARED_PTR_HPP_INCLUDED
#define CPPSHELL_COMMAND_OUTPUT_OBJECT_SHARED_PTR_HPP_INCLUDED

#include <cppshell/command_output/object_fwd.hpp>
#include <memory>

namespace cppshell
{
namespace command_output
{
typedef
std::shared_ptr<cppshell::command_output::object>
object_shared_ptr;
}
}

#endif

