#ifndef CPPSHELL_COMMAND_ARGUMENTS_FROM_STRING_HPP_INCLUDED
#define CPPSHELL_COMMAND_ARGUMENTS_FROM_STRING_HPP_INCLUDED

#include <cppshell/command_arguments.hpp>
#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
cppshell::command_arguments const
command_arguments_from_string(
	std::string const &);
}

#endif

