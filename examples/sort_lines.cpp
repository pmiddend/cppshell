#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/fd_to_ostream.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/command_output/object_scoped_ptr.hpp>
#include <cppshell/posix/open.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


int main(
	int,
	char *argv[])
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
				"sort"
			},
			cppshell::error_stream_flags_field{},
			cppshell::execute_command(
				context,
				cppshell::command_arguments
				{
					"cat"
				},
				cppshell::error_stream_flags_field{},
				cppshell::posix::open(
					argv[1],
					cppshell::posix::open_flags_field{
						cppshell::posix::open_flags::read}))->release_output())};

	cppshell::fd_to_ostream(
		*output->release_output(),
		std::cout);

	cppshell::fd_to_ostream(
		*output->release_error(),
		std::cerr);
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
