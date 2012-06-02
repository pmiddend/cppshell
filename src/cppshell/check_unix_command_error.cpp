#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cerrno>
#include <cstring>
#include <stdexcept>
#include <fcppt/config/external_end.hpp>


void
cppshell::check_unix_command_error(
	std::string const &_command_name,
	int const _error_code)
{
	if(_error_code == -1)
		throw
			cppshell::exception(
				_command_name+
				" failed: "+
				std::strerror(
					errno));
}
