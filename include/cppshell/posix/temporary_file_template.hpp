#ifndef CPPSHELL_POSIX_TEMPORARY_FILE_TEMPLATE_HPP_INCLUDED
#define CPPSHELL_POSIX_TEMPORARY_FILE_TEMPLATE_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
FCPPT_MAKE_STRONG_TYPEDEF(
	boost::filesystem::path,
	temporary_file_template);
}
}

#endif

