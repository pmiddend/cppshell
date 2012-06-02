#include <cppshell/context.hpp>
#include <cppshell/posix/wait_for_process.hpp>
#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


cppshell::context::context()
:
	processes_()
{
}

void
cppshell::context::add_process(
	cppshell::posix::process_id const &_process_id,
	cppshell::optional_process_description const &_process_description)
{
	processes_.push_back(
		process_tuple{
			_process_id,
			_process_description});
}

void
cppshell::context::wait_for_processes()
{
	for(
		cppshell::context::process_tuple const &current_tuple : processes_)
	{
		if(
			cppshell::posix::wait_for_process(
				std::get<cppshell::context::process_id_index>(
					current_tuple)).get())
		{
			std::string const process_description{
				std::get<process_description_index>(
					current_tuple)
				?
					*std::get<process_description_index>(
						current_tuple)
				:
					std::string{
						"<unknown id>"}};

			std::cerr
				<< "Process \""
				<< process_description
				<< "\" failed!\n";
		}
	}

	processes_.clear();
}

cppshell::context::~context()
{
	this->wait_for_processes();
}
