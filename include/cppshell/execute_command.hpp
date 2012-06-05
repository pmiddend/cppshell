#ifndef CPPSHELL_EXECUTE_COMMAND_HPP_INCLUDED
#define CPPSHELL_EXECUTE_COMMAND_HPP_INCLUDED

#include <cppshell/command_arguments.hpp>
#include <cppshell/context_fwd.hpp>
#include <cppshell/error_stream_flags_field.hpp>
#include <cppshell/optional_input_fd.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/command_output/object_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
cppshell::command_output::object_unique_ptr
execute_command(
	cppshell::context &,
	cppshell::command_arguments const &,
	cppshell::error_stream_flags_field const &,
	cppshell::optional_input_fd);
}

#endif

