#ifndef CPPSHELL_STRONG_FD_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_HPP_INCLUDED

#include <cppshell/noncopyable.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>


namespace cppshell
{
class strong_fd
{
CPPSHELL_NONCOPYABLE(
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

