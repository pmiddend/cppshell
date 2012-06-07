#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/fd_to_ostream.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/command_output/object_scoped_ptr.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


int main()
try
{
	cppshell::context context{
		cppshell::process::wait_for_completion{
			true}};

	cppshell::command_output::object_scoped_ptr output{
		cppshell::execute_command(
			context,
			cppshell::command_arguments
			{
				"wc",
				"-c"
			},
			cppshell::stderr_to_stdout{
				false},
			cppshell::execute_command(
				context,
				cppshell::command_arguments
				{
					"/etc/passwd"
				},
				cppshell::stderr_to_stdout{
					false},
				cppshell::optional_input_fd{})->release_output())};

	std::cout << "main: Outputting to stream\n";

	cppshell::fd_to_ostream(
		*output->release_output(),
		std::cout);

	std::cout << "main: Done\n" << std::endl;
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
