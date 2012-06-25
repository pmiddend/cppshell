#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/fd_to_ostream.hpp>
#include <cppshell/command_output/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>


int main(
	int,
	char *argv[])
try
{
	cppshell::context context{
		cppshell::process::wait_for_completion{
			true}};

	cppshell::fd_to_ostream(
		*(cppshell::execute_command(
			context,
			cppshell::command_arguments
			{
				argv[1]
			},
			cppshell::stderr_to_stdout{
				false},
			cppshell::optional_input_fd{})->release_output()),
		std::cout);

}
catch(std::exception const &e)
{
	std::cerr << "Error: " << e.what() << "\n";
	return EXIT_FAILURE;
}
catch(...)
{
	std::cerr << "Unknown exception caught";
	return EXIT_FAILURE;
}
