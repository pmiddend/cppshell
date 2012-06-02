#ifndef CPPSHELL_POSIX_FORK_HPP_INCLUDED
#define CPPSHELL_POSIX_FORK_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
cppshell::posix::process_id_unique_ptr
fork(
	std::function<void ()> const &);
}
}

#endif

