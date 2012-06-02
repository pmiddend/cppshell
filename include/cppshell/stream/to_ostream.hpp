#ifndef CPPSHELL_STREAM_TO_OSTREAM_HPP_INCLUDED
#define CPPSHELL_STREAM_TO_OSTREAM_HPP_INCLUDED

#include <cppshell/stream/object_fwd.hpp>
#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace stream
{
CPPSHELL_SYMBOL
void
to_ostream(
	cppshell::stream::object &,
	std::ostream &);
}
}

#endif

