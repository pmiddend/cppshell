#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/wait_for_process.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcppt/config/external_end.hpp>

cppshell::posix::process_return_value const
cppshell::posix::wait_for_process(
	cppshell::posix::process_id const &_process_id)
{
	int return_value;

	::pid_t const return_value_pid =
		::waitpid(
			_process_id.get(),
			&return_value,
			0);

	cppshell::check_unix_command_error(
		"waitpid",
		static_cast<int>(
			return_value_pid));

	return
		cppshell::posix::process_return_value(
			return_value);
}
