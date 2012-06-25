#ifndef CPPSHELL_GETENV_HPP_INCLUDED
#define CPPSHELL_GETENV_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/optional_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
fcppt::optional<std::string> const
getenv(
	std::string const &);
}

#endif

