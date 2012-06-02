#ifndef CPPSHELL_POSIX_WAIT_FOR_PROCESS_HPP_INCLUDED
#define CPPSHELL_POSIX_WAIT_FOR_PROCESS_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id.hpp>
#include <cppshell/posix/process_return_value.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
cppshell::posix::process_return_value const
wait_for_process(
	cppshell::posix::process_id const &);
}
}

#endif

