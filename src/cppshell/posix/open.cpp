#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/make_unique.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/posix/open.hpp>
#include <cppshell/posix/open_flags_to_posix_flags.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <boost/filesystem/operations.hpp>
#include <fcntl.h>
#include <fcppt/config/external_end.hpp>


cppshell::strong_fd_unique_ptr
cppshell::posix::open(
	boost::filesystem::path const &_path,
	cppshell::posix::open_flags_field const &_open_flags)
{
	int const fd{
		::open(
			boost::filesystem::absolute(
				_path).string<std::string>().c_str(),
			cppshell::posix::open_flags_to_posix_flags(
				_open_flags))};

	cppshell::check_unix_command_error(
		"open",
		fd);

	return
		cppshell::make_unique<cppshell::strong_fd>(
			cppshell::posix::fd{
				fd});
}
