#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/redirect_stderr_to_stdout.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::posix::redirect_stderr_to_stdout()
{
	cppshell::check_unix_command_error(
		"dup2",
		::dup2(
			STDOUT_FILENO,
			STDERR_FILENO));
}
