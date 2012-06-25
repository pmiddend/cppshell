#ifndef CPPSHELL_FILE_CONTENTS_IF_EXISTS_HPP_INCLUDED
#define CPPSHELL_FILE_CONTENTS_IF_EXISTS_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/optional_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
fcppt::optional<std::string> const
file_contents_if_exists(
	boost::filesystem::path const &);
}

#endif

