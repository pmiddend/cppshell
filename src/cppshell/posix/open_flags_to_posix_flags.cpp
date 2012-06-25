#include <cppshell/posix/open_flags_to_posix_flags.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <fcppt/config/external_end.hpp>


int
cppshell::posix::open_flags_to_posix_flags(
	cppshell::posix::open_flags_field const &_open_flags)
{
	int flags = 0;

	if(_open_flags & cppshell::posix::open_flags::read && _open_flags & cppshell::posix::open_flags::write)
		flags = O_RDWR;
	else if (_open_flags & cppshell::posix::open_flags::read)
		flags = O_RDONLY;
	else if (_open_flags & cppshell::posix::open_flags::write)
		flags = O_WRONLY;

	return
		flags;
}
