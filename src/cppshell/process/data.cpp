#include <cppshell/process/data.hpp>

cppshell::process::data::data()
:
	process_id_{
		-1},
	optional_description_{
		std::string{
			""}}
{
}

cppshell::process::data::data(
	cppshell::posix::process_id const &_process_id,
	cppshell::process::optional_description const &_optional_description)
:
	process_id_{
		_process_id},
	optional_description_{
		_optional_description}
{
}

cppshell::posix::process_id const &
cppshell::process::data::process_id() const
{
	return
		process_id_;
}

cppshell::process::optional_description const &
cppshell::process::data::optional_description() const
{
	return
		optional_description_;
}
