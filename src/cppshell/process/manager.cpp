#include <cppshell/posix/wait_for_process.hpp>
#include <cppshell/process/manager.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


cppshell::process::manager::manager(
	cppshell::process::wait_for_completion const &_wait_for_completion)
:
	wait_for_completion_{
		_wait_for_completion},
	processes_{}
{
}

void
cppshell::process::manager::add_process(
	cppshell::posix::process_id const &_process_id,
	cppshell::process::optional_description const &_optional_description)
{
	processes_.push_back(
		cppshell::process::data(
			_process_id,
			_optional_description));
}

void
cppshell::process::manager::wait_for_processes()
{
	for(
		cppshell::process::data const &p : processes_)
	{
		if(
			!cppshell::posix::wait_for_process(
				p.process_id()).get())
			continue;

		std::string const process_description{
			p.optional_description()
			?
				*p.optional_description()
			:
				std::string{
					"<unknown id>"}};

		std::cerr
			<< "Process \""
			<< process_description
			<< "\" failed!\n";
	}

	processes_.clear();
}

cppshell::process::manager::~manager()
{
	if(wait_for_completion_.get())
		this->wait_for_processes();
}
