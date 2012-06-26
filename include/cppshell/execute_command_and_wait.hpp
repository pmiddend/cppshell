#ifndef CPPSHELL_EXECUTE_COMMAND_AND_WAIT_HPP_INCLUDED
#define CPPSHELL_EXECUTE_COMMAND_AND_WAIT_HPP_INCLUDED

#include <cppshell/command_arguments.hpp>
#include <cppshell/context_fwd.hpp>
#include <cppshell/optional_input_fd.hpp>
#include <cppshell/stderr_to_stdout.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_return_value.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
cppshell::posix::process_return_value const
execute_command_and_wait(
	cppshell::context &,
	cppshell::command_arguments const &,
	cppshell::stderr_to_stdout const &,
	cppshell::optional_input_fd);
}

#endif

