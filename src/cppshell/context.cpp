#include <cppshell/context.hpp>

cppshell::context::context(
	cppshell::process::wait_for_completion const &_wait_for_completion)
:
	process_manager_{
		_wait_for_completion},
	output_manager_{}
{
}

cppshell::process::manager &
cppshell::context::process_manager()
{
	return
		process_manager_;
}

cppshell::process::manager const &
cppshell::context::process_manager() const
{
	return
		process_manager_;
}

cppshell::output::manager &
cppshell::context::output_manager()
{
	return
		output_manager_;
}

cppshell::output::manager const &
cppshell::context::output_manager() const
{
	return
		output_manager_;
}

cppshell::context::~context()
{
}
