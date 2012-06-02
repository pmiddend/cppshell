#ifndef CPPSHELL_POSIX_PIPE_HPP_INCLUDED
#define CPPSHELL_POSIX_PIPE_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/stream/object_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace cppshell
{
namespace posix
{
class pipe
{
FCPPT_NONCOPYABLE(
	pipe);
public:
	CPPSHELL_SYMBOL
	pipe();

	CPPSHELL_SYMBOL
	cppshell::stream::object_unique_ptr
	release_read_end();

	CPPSHELL_SYMBOL
	cppshell::stream::object_unique_ptr
	release_write_end();

	CPPSHELL_SYMBOL
	~pipe();
private:
	cppshell::stream::object_unique_ptr read_end_;
	cppshell::stream::object_unique_ptr write_end_;
};
}
}

#endif

