#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/make_unique.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/posix/temporary_file.hpp>
#include <cppshell/posix/temporary_file_template.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <algorithm>
#include <cstdlib>
#include <memory>
#include <unistd.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


cppshell::posix::temporary_file::temporary_file(
	cppshell::posix::temporary_file_template const &_prefix)
:
	fd_{},
	path_{}
{
	std::string const appended_template{
		(boost::filesystem::absolute(_prefix.get()) / "XXXXXX")
			.string<std::string>()};

	std::unique_ptr<char[]> prefix{
		new char[appended_template.length()+1]};

	std::copy(
		appended_template.begin(),
		appended_template.end(),
		&prefix[0]);

	prefix[appended_template.length()] =
		0;

	int const returned_fd{
		::mkstemp(
			&prefix[0])};

	cppshell::check_unix_command_error(
		"mkstemp",
		returned_fd);

	fd_ =
		cppshell::make_unique<cppshell::strong_fd>(
			cppshell::posix::fd{
			returned_fd});

	path_ =
		&prefix[0];
}

cppshell::posix::fd const
cppshell::posix::temporary_file::fd() const
{
	return
		fd_->value();
}

boost::filesystem::path const
cppshell::posix::temporary_file::path() const
{
	return
		path_;
}

cppshell::posix::temporary_file::~temporary_file()
{
	fd_.reset();
	cppshell::check_unix_command_error(
		"unlink",
		::unlink(
			path_.string<std::string>().c_str()));
}
