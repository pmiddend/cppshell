#ifndef CPPSHELL_STREAM_OBJECT_HPP_INCLUDED
#define CPPSHELL_STREAM_OBJECT_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>
#include <fcppt/noncopyable.hpp>

namespace cppshell
{
namespace stream
{
class object
{
public:
	CPPSHELL_SYMBOL
	explicit
	object(
		cppshell::posix::fd const &);

	CPPSHELL_SYMBOL
	cppshell::posix::fd const &
	fd() const;

	void
	dont_close_on_destruction();

	CPPSHELL_SYMBOL
	~object();
private:
	cppshell::posix::fd const fd_;
	bool close_on_destruction_;
};
}
}

#endif

