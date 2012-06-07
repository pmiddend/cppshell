#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/posix/exec.hpp>
#include <cppshell/posix/fork.hpp>
#include <cppshell/posix/pipe.hpp>
#include <cppshell/posix/redirect_stderr_to_stdout.hpp>
#include <cppshell/posix/redirect_to_fd.hpp>
#include <cppshell/posix/stderr_fd.hpp>
#include <cppshell/posix/stdin_fd.hpp>
#include <cppshell/posix/stdout_fd.hpp>
#include <cppshell/make_unique.hpp>
#include <utility>
#include <fcppt/optional.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/assert/pre_message.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


namespace
{
void
forked_function(
	cppshell::command_arguments const &_elements,
	cppshell::optional_input_fd &_optional_input_fd,
	cppshell::posix::pipe &out_pipe,
	cppshell::posix::pipe &err_pipe,
	cppshell::stderr_to_stdout const &_stderr_to_stdout)
{
	out_pipe.release_read_end();
	err_pipe.release_read_end();

	cppshell::strong_fd_unique_ptr
		out_write_end{
			out_pipe.release_write_end()},
		err_write_end{
			err_pipe.release_write_end()};

	cppshell::posix::redirect_to_fd(
		out_write_end->value(),
		cppshell::posix::stdout_fd());

	cppshell::posix::redirect_to_fd(
		err_write_end->value(),
		cppshell::posix::stderr_fd());

	if(_stderr_to_stdout.get())
		cppshell::posix::redirect_stderr_to_stdout();

	if(_optional_input_fd)
		cppshell::posix::redirect_to_fd(
			_optional_input_fd->value(),
			cppshell::posix::stdin_fd());

	cppshell::posix::exec(
		_elements);
}
}

cppshell::command_output::object_unique_ptr
cppshell::execute_command(
	cppshell::context &_context,
	cppshell::command_arguments const &_elements,
	cppshell::stderr_to_stdout const &_stderr_to_stdout,
	cppshell::optional_input_fd _optional_input_fd)
{
	FCPPT_ASSERT_PRE_MESSAGE(
		!_elements.empty(),
		FCPPT_TEXT("Command gets no argument!"));

	cppshell::posix::pipe out_pipe,err_pipe;

	cppshell::posix::process_id_unique_ptr pid{
		cppshell::posix::fork(
			std::bind(
				&::forked_function,
				_elements,
				std::ref(
					_optional_input_fd),
				std::ref(
					out_pipe),
				std::ref(
					err_pipe),
				_stderr_to_stdout))};

	out_pipe.release_write_end();
	err_pipe.release_write_end();

	cppshell::strong_fd_unique_ptr error_stream_ptr{};

	return
		cppshell::make_unique<cppshell::command_output::object>(
			std::ref(
				_context),
			out_pipe.release_read_end(),
			err_pipe.release_read_end(),
			std::move(
				pid),
			cppshell::process::optional_description{
				_elements.front()});
}
