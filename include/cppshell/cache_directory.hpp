#ifndef CPPSHELL_CACHE_DIRECTORY_HPP_INCLUDED
#define CPPSHELL_CACHE_DIRECTORY_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
CPPSHELL_SYMBOL
boost::filesystem::path const
cache_directory(
	std::string const &_app_name);
}

#endif

