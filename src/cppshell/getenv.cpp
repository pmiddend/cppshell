#include <cppshell/getenv.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


fcppt::optional<std::string> const
cppshell::getenv(
	std::string const &_input)
{
	char * const var{
		std::getenv(
			_input.c_str())};

	if(!var)
		return
			fcppt::optional<std::string>{};

	return
		fcppt::optional<std::string>{
			std::string{
				var}};
}
