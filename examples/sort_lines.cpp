#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/command_output/object_scoped_ptr.hpp>
#include <cppshell/stream/from_file.hpp>
#include <cppshell/stream/object.hpp>
#include <cppshell/stream/object_scoped_ptr.hpp>
#include <cppshell/stream/to_ostream.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


int main(
	int argc,
	char *argv[])
try
{
	cppshell::context context;

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
				cppshell::stream::from_file(
					argv[1]))->release_output())};

	cppshell::stream::to_ostream(
		*output->release_output(),
		std::cout);

	cppshell::stream::to_ostream(
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
