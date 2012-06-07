#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/posix/pipe.hpp>
#include <cppshell/make_unique.hpp>
#include <utility>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::posix::pipe::pipe()
:
	read_end_(),
	write_end_()
{
	int pipes[2];

	cppshell::check_unix_command_error(
		"pipe",
		::pipe(
			pipes));

	read_end_ =
		cppshell::make_unique<cppshell::strong_fd>(
			cppshell::posix::fd(
				pipes[0]));

	write_end_ =
		cppshell::make_unique<cppshell::strong_fd>(
			cppshell::posix::fd(
				pipes[1]));
}

cppshell::strong_fd_unique_ptr
cppshell::posix::pipe::release_read_end()
{
	return
		std::move(
			read_end_);
}

cppshell::strong_fd_unique_ptr
cppshell::posix::pipe::release_write_end()
{
	return
		std::move(
			write_end_);
}

cppshell::posix::pipe::~pipe()
{
}
