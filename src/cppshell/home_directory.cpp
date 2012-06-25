#include <cppshell/getenv.hpp>
#include <cppshell/home_directory.hpp>
#include <fcppt/optional.hpp>


boost::filesystem::path const
cppshell::home_directory()
{
	return
		*cppshell::getenv(
			std::string{
				"HOME"});
}
