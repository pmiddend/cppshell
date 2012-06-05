#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/redirect_to_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::posix::redirect_to_fd(
	cppshell::posix::fd const &_from,
	cppshell::posix::fd const &_to)
{
	cppshell::check_unix_command_error(
		"dup2",
		::dup2(
			_from.get(),
			_to.get()));
}
