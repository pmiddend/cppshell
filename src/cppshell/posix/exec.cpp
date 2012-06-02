#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/posix/exec.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <cstring>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
cppshell::posix::exec(
	cppshell::command_arguments const &_args)
{
        char **newargv =
                new char*[
                        static_cast<std::size_t>(
                                _args.size()+1)];

	cppshell::command_arguments::const_iterator current_argument =
		_args.begin();

        for(
                std::size_t i =
                        static_cast<std::size_t>(0);
                i < _args.size();
                ++i)
        {
                newargv[i] =
                        new char[
                                static_cast<std::size_t>(
                                        current_argument->size()+1)];

                std::strcpy(
                        newargv[i],
			current_argument->c_str());

		++current_argument;
        }

        newargv[
                static_cast<std::size_t>(
                        _args.size())] = 0;

        cppshell::check_unix_command_error(
		"execvp",
		::execvp(
			_args.begin()->c_str(),
			newargv));

}
