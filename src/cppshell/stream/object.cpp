#include <cppshell/stream/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::stream::object::object(
	int const _fd)
:
	fd_(
		_fd)
{
}

int
cppshell::stream::object::fd() const
{
	return fd_;
}

cppshell::stream::object::~object()
{
	int const error_code =
		::close(
			fd_);

	if(error_code)
		std::cerr << "Closing a stream failed: " << std::strerror(errno) << "\n";
}
