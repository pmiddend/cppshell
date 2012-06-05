#ifndef CPPSHELL_POSIX_REDIRECT_TO_FD_HPP_INCLUDED
#define CPPSHELL_POSIX_REDIRECT_TO_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
void
redirect_to_fd(
	cppshell::posix::fd const &from,
	cppshell::posix::fd const &to);
}
}

#endif

