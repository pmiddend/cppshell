#include <cppshell/stream/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::stream::object::object(
	cppshell::posix::fd const &_fd)
:
	fd_{
		_fd},
	close_on_destruction_{
		true}
{
}

cppshell::posix::fd const &
cppshell::stream::object::fd() const
{
	return
		fd_;
}

void
cppshell::stream::object::dont_close_on_destruction()
{
	close_on_destruction_ =
		false;
}

cppshell::stream::object::~object()
{
	if(close_on_destruction_)
	{
		int const error_code =
			::close(
				fd_.get());

		if(error_code)
			std::cerr << "Closing a stream failed: " << std::strerror(errno) << "\n";
	}
}
