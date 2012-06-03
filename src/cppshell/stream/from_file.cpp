#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/stream/from_file.hpp>
#include <cppshell/stream/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <boost/filesystem/operations.hpp>
#include <fcppt/config/external_end.hpp>


cppshell::stream::object_unique_ptr
cppshell::stream::from_file(
	boost::filesystem::path const &_path)
{
	std::string const absolute_path =
		boost::filesystem::absolute(
			_path).string<std::string>();

	cppshell::posix::fd const return_value{
		::open(
			absolute_path.c_str(),
			O_RDONLY)};

	cppshell::check_unix_command_error(
		"open(\""+
		absolute_path+
		"\")",
		return_value.get());

	return
		fcppt::make_unique_ptr<cppshell::stream::object>(
			return_value);
}
