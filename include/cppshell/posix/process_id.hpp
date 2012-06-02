#ifndef CPPSHELL_PROCESS_ID_HPP_INCLUDED
#define CPPSHELL_PROCESS_ID_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
FCPPT_MAKE_STRONG_TYPEDEF(
	::pid_t,
	process_id);
}
}

#endif

