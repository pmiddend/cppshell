#ifndef CPPSHELL_CHECK_UNIX_COMMAND_ERROR_HPP_INCLUDED
#define CPPSHELL_CHECK_UNIX_COMMAND_ERROR_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
void
check_unix_command_error(
	std::string const &command_name,
	int);
}

#endif

