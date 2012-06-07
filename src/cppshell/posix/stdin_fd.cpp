#include <cppshell/posix/stdin_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdio.h>
#include <fcppt/config/external_end.hpp>


cppshell::posix::fd const &
cppshell::posix::stdin_fd()
{
	static cppshell::posix::fd result{
		STDIN_FILENO};

	return result;
}
