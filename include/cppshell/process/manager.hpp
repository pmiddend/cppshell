#ifndef CPPSHELL_PROCESS_MANAGER_HPP_INCLUDED
#define CPPSHELL_PROCESS_MANAGER_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id.hpp>
#include <cppshell/process/data.hpp>
#include <cppshell/process/optional_description.hpp>
#include <cppshell/process/wait_for_completion.hpp>
#include <cppshell/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace process
{
class manager
{
CPPSHELL_NONCOPYABLE(
	manager);
public:
	CPPSHELL_SYMBOL
	explicit
	manager(
		cppshell::process::wait_for_completion const &);

	CPPSHELL_SYMBOL
	void
	add_process(
		cppshell::posix::process_id const &,
		cppshell::process::optional_description const &);

	CPPSHELL_SYMBOL
	void
	wait_for_processes();

	CPPSHELL_SYMBOL
	~manager();
private:
	typedef
	std::vector<cppshell::process::data>
	process_sequence;

	cppshell::process::wait_for_completion const wait_for_completion_;
	process_sequence processes_;
};
}
}

#endif

