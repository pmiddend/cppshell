#ifndef CPPSHELL_CONTEXT_HPP_INCLUDED
#define CPPSHELL_CONTEXT_HPP_INCLUDED

#include <cppshell/optional_process_description.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
class context
{
FCPPT_NONCOPYABLE(
	context);
public:
	CPPSHELL_SYMBOL
	context();

	CPPSHELL_SYMBOL
	void
	add_process(
		cppshell::posix::process_id const &,
		cppshell::optional_process_description const &);

	CPPSHELL_SYMBOL
	void
	wait_for_processes();

	CPPSHELL_SYMBOL
	~context();
private:
	typedef
	std::tuple
	<
		cppshell::posix::process_id,
		cppshell::optional_process_description
	>
	process_tuple;

	static std::size_t const process_id_index = 0u;
	static std::size_t const process_description_index = 1u;

	typedef
	std::vector<process_tuple>
	process_sequence;

	process_sequence processes_;
};
}

#endif

