#ifndef CPPSHELL_POSIX_PERMISSIONS_UNDERLYING_ENUM_HPP_INCLUDED
#define CPPSHELL_POSIX_PERMISSIONS_UNDERLYING_ENUM_HPP_INCLUDED

namespace cppshell
{
namespace posix
{
namespace permissions
{
namespace underlying_enum
{
enum type
{
	owner_read,
	group_read,
	others_read,
	owner_write,
	group_write,
	others_write,
	owner_execute,
	group_execute,
	others_execute,
	set_user_id,
	set_group_id,
	sticky,
	size

};
}
}
}
}

#endif

