#ifndef CPPSHELL_POSIX_REDIRECT_STREAM_TO_FD_HPP_INCLUDED
#define CPPSHELL_POSIX_REDIRECT_STREAM_TO_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/stream/object_fwd.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
void
redirect_stream_to_fd(
	cppshell::stream::object &,
	int);
}
}

#endif

