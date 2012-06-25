#ifndef CPPSHELL_POSIX_PIPE_HPP_INCLUDED
#define CPPSHELL_POSIX_PIPE_HPP_INCLUDED

#include <cppshell/noncopyable.hpp>
#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>


namespace cppshell
{
namespace posix
{
class pipe
{
CPPSHELL_NONCOPYABLE(
	pipe);
public:
	CPPSHELL_SYMBOL
	pipe();

	CPPSHELL_SYMBOL
	cppshell::strong_fd_unique_ptr
	release_read_end();

	CPPSHELL_SYMBOL
	cppshell::strong_fd_unique_ptr
	release_write_end();

	CPPSHELL_SYMBOL
	~pipe();
private:
	cppshell::strong_fd_unique_ptr read_end_;
	cppshell::strong_fd_unique_ptr write_end_;
};
}
}

#endif

