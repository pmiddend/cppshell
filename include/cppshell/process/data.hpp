#ifndef CPPSHELL_PROCESS_DATA_HPP_INCLUDED
#define CPPSHELL_PROCESS_DATA_HPP_INCLUDED

#include <cppshell/posix/process_id.hpp>
#include <cppshell/process/optional_description.hpp>
#include <fcppt/optional.hpp>

namespace cppshell
{
namespace process
{
class data
{
public:
	data();

	data(
		cppshell::posix::process_id const &,
		cppshell::process::optional_description const &);

	cppshell::posix::process_id const &
	process_id() const;

	cppshell::process::optional_description const &
	optional_description() const;
private:
	cppshell::posix::process_id process_id_;
	cppshell::process::optional_description optional_description_;
};
}
}

#endif

