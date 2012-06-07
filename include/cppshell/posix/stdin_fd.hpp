#ifndef CPPSHELL_POSIX_STDIN_FD_HPP_INCLUDED
#define CPPSHELL_POSIX_STDIN_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
cppshell::posix::fd const &
stdin_fd();
}
}

#endif

