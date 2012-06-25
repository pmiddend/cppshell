#include <cppshell/getenv.hpp>
#include <cppshell/warning_stream.hpp>
#include <cppshell/path_for_executable.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{
cppshell::optional_path const
path_for_executable_part(
	std::string const &_needle,
	boost::filesystem::path const &_haystack)
{
	// directory_iterator fails if _haystack doesn't exist, so purge it
	if(!boost::filesystem::exists(_haystack))
	{
		cppshell::warning_stream() << "directory in $PATH doesn't exist: " << _haystack << "\n";
		return
			cppshell::optional_path{};
	}

	for(
		boost::filesystem::directory_iterator haystack_it{
			_haystack};
		haystack_it != boost::filesystem::directory_iterator{};
		++haystack_it)
		if(haystack_it->path().stem().string<std::string>() == _needle)
			return
				cppshell::optional_path{
					haystack_it->path()};


	return
		cppshell::optional_path{};
}
}

cppshell::optional_path const
cppshell::path_for_executable(
	std::string const &_executable)
{
	fcppt::optional<std::string> const optional_path{
		cppshell::getenv(
			"PATH")};

	if(!optional_path)
		return cppshell::optional_path{};

	typedef
	std::vector<std::string>
	string_vector;

	string_vector paths;

	boost::algorithm::split(
		paths,
		*optional_path,
		boost::algorithm::is_any_of(
			":"));

	for(
		std::string const &p : paths)
	{
		cppshell::optional_path const temp_result{
			::path_for_executable_part(
				_executable,
				p)};

		if(
			temp_result)
			return
				temp_result;
	}

	return
		cppshell::optional_path{};
}
