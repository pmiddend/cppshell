#ifndef CPPSHELL_HOME_DIRECTORY_HPP_INCLUDED
#define CPPSHELL_HOME_DIRECTORY_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
boost::filesystem::path const
home_directory();
}

#endif

