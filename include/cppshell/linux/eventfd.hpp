#ifndef CPPSHELL_LINUX_EVENTFD_HPP_INCLUDED
#define CPPSHELL_LINUX_EVENTFD_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>
#include <cppshell/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace linux
{
class eventfd
{
CPPSHELL_NONCOPYABLE(
	eventfd);
public:
	typedef
	int
	initial_value_type;

	typedef
	std::uint64_t
	value_type;

	CPPSHELL_SYMBOL
	explicit
	eventfd(
		initial_value_type);

	CPPSHELL_SYMBOL
	void
	add(
		value_type);

	CPPSHELL_SYMBOL
	cppshell::posix::fd const &
	fd() const;

	CPPSHELL_SYMBOL
	~eventfd();
private:
	cppshell::posix::fd fd_;
};
}
}

#endif

