#include <cppshell/exception.hpp>
#include <cppshell/linux/eventfd.hpp>
#include <fcppt/insert_to_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/eventfd.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


cppshell::linux::eventfd::eventfd(
	initial_value_type const _initial_value)
:
	fd_{
		::eventfd(
			_initial_value,
			0)}
{
}

void
cppshell::linux::eventfd::add(
	value_type const _addition)
{
	if(ssize_t const bytes_read = ::write(fd_.get(),&_addition,sizeof(value_type)) != sizeof(value_type))
		throw
			cppshell::exception{
				"Couldn't (completely) write to eventfd, only wrote "+
				fcppt::insert_to_std_string(
					bytes_read)+
				" bytes"};
}

cppshell::posix::fd const &
cppshell::linux::eventfd::fd() const
{
	return
		fd_;
}

cppshell::linux::eventfd::~eventfd()
{
}
