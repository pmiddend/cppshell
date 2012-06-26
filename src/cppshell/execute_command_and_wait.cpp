#include <cppshell/execute_command_and_wait.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/posix/stdout_fd.hpp>
#include <cppshell/posix/wait_for_process.hpp>
#include <cppshell/posix/stderr_fd.hpp>
#include <cppshell/context.hpp>
#include <cppshell/output/manager.hpp>
#include <cppshell/command_output/object.hpp>
#include <utility>

cppshell::posix::process_return_value const
cppshell::execute_command_and_wait(
	cppshell::context &_context,
	cppshell::command_arguments const &_arguments,
	cppshell::stderr_to_stdout const &_stderr_to_stdout,
	cppshell::optional_input_fd _optional_input_fd)
{
	cppshell::command_output::object_unique_ptr const output{
		cppshell::execute_command(
			_context,
			std::move(
				_arguments),
			_stderr_to_stdout,
			std::move(
				_optional_input_fd))};

	_context.output_manager().add_asynchronous_redirection(
		output->release_output(),
		cppshell::output::redirection_target{
			cppshell::posix::stdout_fd()});

	_context.output_manager().add_asynchronous_redirection(
		output->release_error(),
		cppshell::output::redirection_target{
			cppshell::posix::stderr_fd()});

	return
		cppshell::posix::wait_for_process(
			*output->release_process_id());
}
