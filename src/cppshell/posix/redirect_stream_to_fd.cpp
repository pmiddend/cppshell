#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/redirect_stream_to_fd.hpp>
#include <cppshell/stream/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::posix::redirect_stream_to_fd(
	cppshell::stream::object &_stream,
	int const _fd)
{
	cppshell::check_unix_command_error(
		"dup2",
		::dup2(
			_stream.fd(),
			_fd));
}
