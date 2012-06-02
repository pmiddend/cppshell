#ifndef CPPSHELL_STREAM_FROM_FILE_HPP_INCLUDED
#define CPPSHELL_STREAM_FROM_FILE_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/stream/object_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace stream
{
CPPSHELL_SYMBOL
cppshell::stream::object_unique_ptr
from_file(
	boost::filesystem::path const &);
}
}

#endif

