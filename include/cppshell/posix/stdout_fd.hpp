#ifndef CPPSHELL_POSIX_STDOUT_FD_HPP_INCLUDED
#define CPPSHELL_POSIX_STDOUT_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>

namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
cppshell::posix::fd const &
stdout_fd();
}
}

#endif

