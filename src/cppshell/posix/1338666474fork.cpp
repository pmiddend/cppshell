#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/fork.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::posix::process_id_unique_ptr
cppshell::posix::fork(
	std::function<void ()> const &_function)
{
	cppshell::posix::process_id_unique_ptr id{
		fcppt::make_unique_ptr<cppshell::posix::process_id>(
			::fork())};

	cppshell::check_unix_command_error(
		"fork",
		static_cast<int>(
			id->get()));

	if(id->get() == 0)
		_function();

	return
		id;
}
