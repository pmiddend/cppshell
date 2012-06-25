#include <cppshell/command_arguments_from_string.hpp>
#include <cppshell/cache_directory.hpp>
#include <cppshell/config_directory.hpp>
#include <cppshell/context.hpp>
#include <cppshell/execute_command.hpp>
#include <cppshell/file_contents_if_exists.hpp>
#include <cppshell/path_for_executable.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/command_output/object.hpp>
#include <cppshell/posix/chmod_fd.hpp>
#include <cppshell/posix/temporary_file.hpp>
#include <cppshell/posix/permissions/owner_execute.hpp>
#include <cppshell/posix/permissions/owner_read.hpp>
#include <cppshell/posix/permissions/owner_write.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/program_options.hpp>
#include <cstdlib>
#include <string>
#include <fcppt/config/external_end.hpp>


int
main(
	int argc,
	char *argv[])
{
	std::string const
		cppshell_name{
			argv[0]};

	int const program_name_index{
		argv[1][0] == '-'
		?
			2
		:
			1};

	std::string const argument_string{
		program_name_index == 2
		?
			argv[1]
		:
			""};

	cppshell::command_arguments const cppshell_arguments{
		cppshell::command_arguments_from_string(
			argument_string)};

	std::string const program_name{
		argv[program_name_index]};

	cppshell::command_arguments program_arguments{
		argv+program_name_index+1,
		argv+argc};

	cppshell::context context{
		cppshell::process::wait_for_completion{
			true}};

	boost::program_options::options_description options_description{"Allowed options"};

	options_description.add_options()
		(
			"compiler",
			boost::program_options::value<std::string>()->default_value("/usr/bin/g++")
		);

	boost::program_options::variables_map config;

	fcppt::optional<std::string> const optional_config_file{
		cppshell::file_contents_if_exists(
			cppshell::config_directory("cppshell") / "config.ini")};

	if(optional_config_file)
	{
		std::istringstream config_stream{
			*optional_config_file};

		boost::program_options::store(
			boost::program_options::parse_config_file(
				config_stream,
				options_description),
			config);
	}

	cppshell::posix::temporary_file temporary_executable{
		cppshell::posix::temporary_file_template{
			cppshell::cache_directory(
				"cppshell").string<std::string>()}};

	cppshell::posix::chmod_fd(
		temporary_executable.fd(),
		cppshell::posix::permissions::owner_read |
		cppshell::posix::permissions::owner_execute |
		cppshell::posix::permissions::owner_write);

	boost::filesystem::path compiler_path;

	if(!config.count("compiler"))
	{
		cppshell::optional_path const gcc_path{
			cppshell::path_for_executable(
				"g++")};

		if(!gcc_path)
		{
			std::cerr << "No compiler found. Configure your compiler...\n";
			return EXIT_FAILURE;
		}

		compiler_path =
			*gcc_path;
	}
	else
	{
		compiler_path =
			boost::filesystem::path{
				config["compiler"].as<std::string>()};
	}

	cppshell::command_arguments compiler_arguments;
	compiler_arguments.insert(
		compiler_arguments.end(),
		{
			compiler_path.string<std::string>(),
			std::string{"-x"},
			std::string{"c++"},
			"-o",
			temporary_executable.path().string<std::string>()
		});

	/*
	compiler_arguments.insert(
		compiler_arguments.end(),
		cppshell_arguments.begin(),
		cppshell_arguments.end());
		*/

	compiler_arguments.push_back(
		std::string{
			"-"});

	std::cout << "Compiling to " << temporary_executable.path().string<std::string>() << " using arguments:\n";

	for(std::string const &s : compiler_arguments)
		std::cout << s << "\n";

	cppshell::execute_command(
		context,
		compiler_arguments,
		cppshell::stderr_to_stdout{
			false},
		cppshell::execute_command(
			context,
			cppshell::command_arguments{
				"sed",
				"1d",
				program_name},
			cppshell::stderr_to_stdout{
				false},
			cppshell::optional_input_fd{})->release_output());

	program_arguments.insert(
		program_arguments.begin(),
		temporary_executable.path().string<std::string>());

	std::cout << "Done, executing with the following arguments:\n";

	for(std::string const &s : program_arguments)
		std::cout << s << "\n";

	cppshell::execute_command(
		context,
		program_arguments,
		cppshell::stderr_to_stdout{
			false},
		cppshell::optional_input_fd{});
}
