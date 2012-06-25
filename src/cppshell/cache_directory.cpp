#include <cppshell/cache_directory.hpp>
#include <cppshell/getenv.hpp>
#include <cppshell/home_directory.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <fcppt/config/external_end.hpp>


boost::filesystem::path const
cppshell::cache_directory(
	std::string const &_app_name)
{
	fcppt::optional<std::string> cache_env_var{
		cppshell::getenv(
			"XDG_CACHE_HOME")};

	boost::filesystem::path const p{
		!cache_env_var
		?
			cppshell::home_directory() /
				".cache" /
				_app_name
		:
			boost::filesystem::path{
				*cache_env_var} /
				_app_name};

	boost::filesystem::create_directories(
		p);

	return
		p;
}
