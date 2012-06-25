#include <cppshell/command_arguments_from_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


cppshell::command_arguments const
cppshell::command_arguments_from_string(
	std::string const &_input)
{
	cppshell::command_arguments result;

	boost::algorithm::split(
		result,
		_input,
		boost::algorithm::is_space());

	return
		std::move(
			result);
}
