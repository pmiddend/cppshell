#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/posix/open.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
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
	int flags = 0;

	if(_open_flags & cppshell::posix::open_flags::read && _open_flags & cppshell::posix::open_flags::write)
		flags = O_RDWR;
	else if (_open_flags & cppshell::posix::open_flags::read)
		flags = O_RDONLY;
	else if (_open_flags & cppshell::posix::open_flags::write)
		flags = O_WRONLY;

	int const fd{
		::open(
			boost::filesystem::absolute(
				_path).string<std::string>().c_str(),
			flags)};

	cppshell::check_unix_command_error(
		"open",
		fd);

	return
		fcppt::make_unique_ptr<cppshell::strong_fd>(
			cppshell::posix::fd{
				fd});
}
