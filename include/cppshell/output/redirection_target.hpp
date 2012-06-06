#ifndef CPPSHELL_OUTPUT_REDIRECTION_TARGET_HPP_INCLUDED
#define CPPSHELL_OUTPUT_REDIRECTION_TARGET_HPP_INCLUDED

#include <cppshell/posix/fd.hpp>
#include <fcppt/strong_typedef.hpp>

namespace cppshell
{
namespace output
{
FCPPT_MAKE_STRONG_TYPEDEF(
	cppshell::posix::fd,
	redirection_target);
}
}

#endif

