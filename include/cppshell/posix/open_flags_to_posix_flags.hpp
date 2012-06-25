#ifndef CPPSHELL_POSIX_OPEN_FLAGS_TO_POSIX_FLAGS_HPP_INCLUDED
#define CPPSHELL_POSIX_OPEN_FLAGS_TO_POSIX_FLAGS_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/open_flags_field.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
int
open_flags_to_posix_flags(
	cppshell::posix::open_flags_field const &);
}
}

#endif

