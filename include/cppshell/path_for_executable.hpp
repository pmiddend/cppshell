#ifndef CPPSHELL_PATH_FOR_EXECUTABLE_HPP_INCLUDED
#define CPPSHELL_PATH_FOR_EXECUTABLE_HPP_INCLUDED

#include <cppshell/optional_path.hpp>
#include <cppshell/symbol.hpp>

namespace cppshell
{
CPPSHELL_SYMBOL
cppshell::optional_path const
path_for_executable(
	std::string const &);
}

#endif

