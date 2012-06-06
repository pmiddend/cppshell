#ifndef CPPSHELL_STRONG_FD_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>
#include <fcppt/noncopyable.hpp>


namespace cppshell
{
class strong_fd
{
FCPPT_NONCOPYABLE(
	strong_fd);
public:
	CPPSHELL_SYMBOL
	explicit
	strong_fd(
		cppshell::posix::fd const &);

	CPPSHELL_SYMBOL
	cppshell::posix::fd const &
	value() const;

	CPPSHELL_SYMBOL
	void
	dont_close();

	CPPSHELL_SYMBOL
	~strong_fd();
private:
	cppshell::posix::fd const value_;
	bool close_;
};
}

#endif

