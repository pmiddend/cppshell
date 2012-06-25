#ifndef CPPSHELL_POSIX_CHMOD_FD_HPP_INCLUDED
#define CPPSHELL_POSIX_CHMOD_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>
#include <cppshell/posix/permissions/bitfield.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
void
chmod_fd(
	cppshell::posix::fd const &,
	cppshell::posix::permissions::bitfield const &);
}
}

#endif

