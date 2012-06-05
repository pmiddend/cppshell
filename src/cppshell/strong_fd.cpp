#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/strong_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::strong_fd::strong_fd(
	cppshell::posix::fd const &_value)
:
	value_{
		_value},
	close_{
		true}
{
}

cppshell::posix::fd const &
cppshell::strong_fd::value() const
{
	return
		value_;
}

void
cppshell::strong_fd::dont_close()
{
	close_ =
		false;
}

cppshell::strong_fd::~strong_fd()
{
	if(close_)
		cppshell::check_unix_command_error(
			"close",
			::close(
				value_.get()));
}
