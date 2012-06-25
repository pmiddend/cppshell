#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/chmod_fd.hpp>
#include <cppshell/posix/fd.hpp>
#include <cppshell/posix/permissions/group_execute.hpp>
#include <cppshell/posix/permissions/group_read.hpp>
#include <cppshell/posix/permissions/group_write.hpp>
#include <cppshell/posix/permissions/others_execute.hpp>
#include <cppshell/posix/permissions/others_read.hpp>
#include <cppshell/posix/permissions/others_write.hpp>
#include <cppshell/posix/permissions/owner_execute.hpp>
#include <cppshell/posix/permissions/owner_read.hpp>
#include <cppshell/posix/permissions/owner_write.hpp>
#include <cppshell/posix/permissions/set_group_id.hpp>
#include <cppshell/posix/permissions/set_user_id.hpp>
#include <cppshell/posix/permissions/sticky.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/stat.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::posix::chmod_fd(
	cppshell::posix::fd const &_fd,
	cppshell::posix::permissions::bitfield const &_field)
{
	mode_t mode{
		0};

	if(_field & cppshell::posix::permissions::owner_read)
		mode |= S_IRUSR;

	if(_field & cppshell::posix::permissions::owner_write)
		mode |= S_IWUSR;

	if(_field & cppshell::posix::permissions::owner_execute)
		mode |= S_IXUSR;

	if(_field & cppshell::posix::permissions::group_read)
		mode |= S_IRGRP;

	if(_field & cppshell::posix::permissions::group_write)
		mode |= S_IWGRP;

	if(_field & cppshell::posix::permissions::group_execute)
		mode |= S_IXGRP;

	if(_field & cppshell::posix::permissions::others_read)
		mode |= S_IROTH;

	if(_field & cppshell::posix::permissions::others_write)
		mode |= S_IWOTH;

	if(_field & cppshell::posix::permissions::others_execute)
		mode |= S_IXOTH;

	if(_field & cppshell::posix::permissions::set_user_id)
		mode |= S_ISUID;

	if(_field & cppshell::posix::permissions::set_group_id)
		mode |= S_ISGID;

	if(_field & cppshell::posix::permissions::sticky)
		mode |= S_ISVTX;

	cppshell::check_unix_command_error(
		"fchmod",
		::fchmod(
			_fd.get(),
			mode));
}
