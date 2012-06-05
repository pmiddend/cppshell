#ifndef CPPSHELL_FD_TO_OSTREAM_HPP_INCLUDED
#define CPPSHELL_FD_TO_OSTREAM_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
void
fd_to_ostream(
	cppshell::strong_fd const &,
	std::ostream &);
}

#endif

