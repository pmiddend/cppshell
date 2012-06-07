#include <cppshell/context.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/posix/stderr_fd.hpp>
#include <cppshell/posix/stdout_fd.hpp>
#include <utility>


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
		std::move(
			_output)},
	error_{
		std::move(
			_error)},
	process_id_{
		std::move(
			_process_id)},
	process_description_{
		_process_description}
{
}

cppshell::strong_fd_unique_ptr
cppshell::command_output::object::release_output()
{
	return
		std::move(
			output_);
}

cppshell::strong_fd_unique_ptr
cppshell::command_output::object::release_error()
{
	return
		std::move(
			error_);
}

cppshell::posix::process_id_unique_ptr
cppshell::command_output::object::release_process_id()
{
	return
		std::move(
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
		context_.output_manager().add_asynchronous_redirection(
			std::move(
				error_),
			cppshell::output::redirection_target{
				cppshell::posix::stderr_fd()});
	}

	if(
		output_)
	{
		context_.output_manager().add_asynchronous_redirection(
			std::move(
				output_),
			cppshell::output::redirection_target{
				cppshell::posix::stdout_fd()});
	}
}
