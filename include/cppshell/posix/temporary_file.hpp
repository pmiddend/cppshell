#ifndef CPPSHELL_POSIX_TEMPORARY_FILE_HPP_INCLUDED
#define CPPSHELL_POSIX_TEMPORARY_FILE_HPP_INCLUDED

#include <cppshell/noncopyable.hpp>
#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/fd.hpp>
#include <cppshell/posix/temporary_file_template.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
class temporary_file
{
CPPSHELL_NONCOPYABLE(
	temporary_file);
public:
	CPPSHELL_SYMBOL
	explicit
	temporary_file(
		cppshell::posix::temporary_file_template const &);

	CPPSHELL_SYMBOL
	cppshell::posix::fd const
	fd() const;

	CPPSHELL_SYMBOL
	boost::filesystem::path const
	path() const;

	CPPSHELL_SYMBOL
	~temporary_file();
private:
	cppshell::strong_fd_unique_ptr fd_;
	boost::filesystem::path path_;
};
}
}

#endif

