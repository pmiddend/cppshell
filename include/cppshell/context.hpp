#ifndef CPPSHELL_CONTEXT_HPP_INCLUDED
#define CPPSHELL_CONTEXT_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/output/manager.hpp>
#include <cppshell/process/manager.hpp>
#include <cppshell/process/wait_for_completion.hpp>
#include <cppshell/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <thread>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
class context
{
CPPSHELL_NONCOPYABLE(
	context);
public:
	CPPSHELL_SYMBOL
	explicit
	context(
		cppshell::process::wait_for_completion const &);

	CPPSHELL_SYMBOL
	cppshell::process::manager &
	process_manager();

	CPPSHELL_SYMBOL
	cppshell::process::manager const &
	process_manager() const;

	CPPSHELL_SYMBOL
	cppshell::output::manager &
	output_manager();

	CPPSHELL_SYMBOL
	cppshell::output::manager const &
	output_manager() const;

	CPPSHELL_SYMBOL
	~context();
private:
	cppshell::process::manager process_manager_;
	cppshell::output::manager output_manager_;
};
}

#endif

