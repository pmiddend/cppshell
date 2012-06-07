#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/fork.hpp>
#include <cppshell/make_unique.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>
#include <utility>


cppshell::posix::process_id_unique_ptr
cppshell::posix::fork(
	std::function<void ()> const &_function)
{
	cppshell::posix::process_id_unique_ptr id{
		cppshell::make_unique<cppshell::posix::process_id>(
			::fork())};

	cppshell::check_unix_command_error(
		"fork",
		static_cast<int>(
			id->get()));

	if(id->get() == 0)
		_function();

	return
		std::move(
			id);
}
