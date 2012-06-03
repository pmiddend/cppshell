#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/exception.hpp>
#include <cppshell/stream/object.hpp>
#include <cppshell/stream/to_ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <ostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::stream::to_ostream(
	cppshell::stream::object &_stream,
	std::ostream &_ostream)
{
	std::size_t const buffer_size = 1024u;
	std::array<char,buffer_size> buffer;

	while(
		ssize_t const read_bytes =
			::read(
				_stream.fd().get(),
				buffer.data(),
				buffer.size()))
	{
		cppshell::check_unix_command_error(
			"read",
			static_cast<int>(
				read_bytes));

		if(!
			_ostream.write(
				buffer.data(),
				static_cast<std::streamsize>(
					read_bytes)))
			throw
				cppshell::exception{
					std::string{
						"to_ostream failed: ostream::write failed"}};
	}
}
