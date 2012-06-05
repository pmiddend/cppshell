#include <cppshell/strong_fd.hpp>
#include <cppshell/context.hpp>
#include <cppshell/command_output/object.hpp>
#include <fcppt/move.hpp>

cppshell::command_output::object::object(
	cppshell::context &_context,
	cppshell::strong_fd_unique_ptr _output,
	cppshell::strong_fd_unique_ptr _error,
	cppshell::posix::process_id_unique_ptr _process_id,
	cppshell::process::optional_description const &_process_description)
:
	context_(
		_context),
	output_{
		fcppt::move(
			_output)},
	error_{
		fcppt::move(
			_error)},
	process_id_{
		fcppt::move(
			_process_id)},
	process_description_{
		_process_description}
{
}

cppshell::strong_fd_unique_ptr
cppshell::command_output::object::release_output()
{
	return
		fcppt::move(
			output_);
}

cppshell::strong_fd_unique_ptr
cppshell::command_output::object::release_error()
{
	return
		fcppt::move(
			error_);
}

cppshell::posix::process_id_unique_ptr
cppshell::command_output::object::release_process_id()
{
	return
		fcppt::move(
			process_id_);
}

cppshell::command_output::object::~object()
{
	if(
		process_id_)
	{
		context_.process_manager().add_process(
			*process_id_,
			process_description_);
	}

	if(
		error_)
	{
		context_.output_manager().add_asynchronous_output(
			fcppt::move(
				error_));
	}

	if(
		output_)
	{
		context_.output_manager().add_asynchronous_output(
			fcppt::move(
				output_));
	}
}
