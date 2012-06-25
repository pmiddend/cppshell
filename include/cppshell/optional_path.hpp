#ifndef CPPSHELL_OPTIONAL_PATH_HPP_INCLUDED
#define CPPSHELL_OPTIONAL_PATH_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
typedef
fcppt::optional<boost::filesystem::path>
optional_path;
}

#endif

