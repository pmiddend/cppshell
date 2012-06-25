#include <cppshell/posix/temporary_file.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


int main()
{
	cppshell::posix::temporary_file tempfile{
		cppshell::posix::temporary_file_template{
			boost::filesystem::path{
				"/tmp"}}};
	std::cout
		<< "Temporary file created: "
		<< tempfile.path()
		<< "\n";

}
