#include <cppshell/posix/stdout_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdio.h>
#include <fcppt/config/external_end.hpp>


cppshell::posix::fd const &
cppshell::posix::stdout_fd()
{
	static cppshell::posix::fd result{
		STDOUT_FILENO};

	return result;
}
