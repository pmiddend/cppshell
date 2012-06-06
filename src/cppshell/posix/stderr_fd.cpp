#include <cppshell/posix/stderr_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdio.h>
#include <fcppt/config/external_end.hpp>


cppshell::posix::fd const &
cppshell::posix::stderr_fd()
{
	static cppshell::posix::fd result{
		STDERR_FILENO};

	return result;
}
