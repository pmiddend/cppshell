#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/pipe.hpp>
#include <cppshell/stream/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
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
		fcppt::make_unique_ptr<cppshell::stream::object>(
			cppshell::posix::fd(
				pipes[0]));

	write_end_ =
		fcppt::make_unique_ptr<cppshell::stream::object>(
			cppshell::posix::fd(
				pipes[1]));
}

cppshell::stream::object_unique_ptr
cppshell::posix::pipe::release_read_end()
{
	return
		fcppt::move(
			read_end_);
}

cppshell::stream::object_unique_ptr
cppshell::posix::pipe::release_write_end()
{
	return
		fcppt::move(
			write_end_);
}

cppshell::posix::pipe::~pipe()
{
}
