#include <cppshell/warning_stream.hpp>
#include <iostream>

std::ostream &
cppshell::warning_stream()
{
	return
		std::clog << "cppshell: warning: ";
}
