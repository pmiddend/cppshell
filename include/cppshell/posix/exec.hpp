#ifndef CPPSHELL_POSIX_EXEC_HPP_INCLUDED
#define CPPSHELL_POSIX_EXEC_HPP_INCLUDED

#include <cppshell/command_arguments.hpp>
#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
void
exec(
	cppshell::command_arguments const &);
}
}

#endif

