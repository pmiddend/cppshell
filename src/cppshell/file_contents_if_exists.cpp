#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/fd_to_ostream.hpp>
#include <cppshell/file_contents_if_exists.hpp>
#include <cppshell/strong_fd.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <boost/filesystem/operations.hpp>
#include <cerrno>
#include <fcntl.h>
#include <sstream>
#include <fcppt/config/external_end.hpp>


fcppt::optional<std::string> const
cppshell::file_contents_if_exists(
	boost::filesystem::path const &_path)
{
	int const fd{
		::open(
			boost::filesystem::absolute(
				_path).string<std::string>().c_str(),
			O_RDONLY)};

	if(fd == -1)
	{
		if(errno == ENOENT)
			return
				fcppt::optional<std::string>{};

		cppshell::check_unix_command_error(
			"open",
			fd);
	}

	std::stringstream ss;

	cppshell::fd_to_ostream(
		cppshell::strong_fd{
			cppshell::posix::fd{
				fd}},
		ss);

	return
		fcppt::optional<std::string>{
			ss.str()};
}
