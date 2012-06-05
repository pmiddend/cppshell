#ifndef CPPSHELL_POSIX_OPEN_HPP_INCLUDED
#define CPPSHELL_POSIX_OPEN_HPP_INCLUDED

#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/open_flags_field.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
CPPSHELL_SYMBOL
cppshell::strong_fd_unique_ptr
open(
	boost::filesystem::path const &,
	cppshell::posix::open_flags_field const &);
}
}

#endif
