#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/posix/exec.hpp>
#include <cppshell/posix/fork.hpp>
#include <cppshell/posix/pipe.hpp>
#include <cppshell/posix/redirect_stderr_to_stdout.hpp>
#include <cppshell/posix/redirect_stream_to_fd.hpp>
#include <cppshell/stream/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
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
	cppshell::optional_input_stream &_optional_input_stream,
	cppshell::posix::pipe &out_pipe,
	cppshell::posix::pipe &err_pipe,
	cppshell::error_stream_flags_field const &_error_stream_flags)
{
	out_pipe.release_read_end();
	err_pipe.release_read_end();

	cppshell::stream::object_unique_ptr
		out_write_end{
			out_pipe.release_write_end()},
		err_write_end{
			err_pipe.release_write_end()};

	cppshell::posix::redirect_stream_to_fd(
		*out_write_end,
		cppshell::posix::fd{
			STDOUT_FILENO});

	cppshell::posix::redirect_stream_to_fd(
		*err_write_end,
		cppshell::posix::fd{
			STDERR_FILENO});

	if(_error_stream_flags & cppshell::error_stream_flags::redirect_to_output)
	{
		cppshell::posix::redirect_stderr_to_stdout();
	}
	else if(!(_error_stream_flags & cppshell::error_stream_flags::ignore))
	{

	}

	if(_optional_input_stream)
		cppshell::posix::redirect_stream_to_fd(
			*_optional_input_stream,
			cppshell::posix::fd{
				STDIN_FILENO});

	cppshell::posix::exec(
		_elements);
}
}

cppshell::command_output::object_unique_ptr
cppshell::execute_command(
	cppshell::context &_context,
	cppshell::command_arguments const &_elements,
	cppshell::error_stream_flags_field const &_error_stream_flags,
	cppshell::optional_input_stream _optional_input_stream)
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
					_optional_input_stream),
				std::ref(
					out_pipe),
				std::ref(
					err_pipe),
				std::cref(
					_error_stream_flags)))};

	out_pipe.release_write_end();
	err_pipe.release_write_end();

	cppshell::stream::object_unique_ptr error_stream_ptr{};

	if(
		_error_stream_flags & cppshell::error_stream_flags::redirect_to_output ||
		_error_stream_flags & cppshell::error_stream_flags::ignore)
		err_pipe.release_read_end();
	else
		error_stream_ptr =
			err_pipe.release_read_end();

	return
		fcppt::make_unique_ptr<cppshell::command_output::object>(
			fcppt::ref(
				_context),
			out_pipe.release_read_end(),
			fcppt::move(
				error_stream_ptr),
			fcppt::move(
				pid),
			cppshell::optional_process_description{
				_elements.front()});
}
