#ifndef CPPSHELL_COMMAND_OUTPUT_OBJECT_HPP_INCLUDED
#define CPPSHELL_COMMAND_OUTPUT_OBJECT_HPP_INCLUDED

#include <cppshell/context_fwd.hpp>
#include <cppshell/process/optional_description.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id_unique_ptr.hpp>
#include <cppshell/stream/object_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional.hpp>


namespace cppshell
{
namespace command_output
{
class object
{
FCPPT_NONCOPYABLE(
	object);
public:
	CPPSHELL_SYMBOL
	object(
		cppshell::context &,
		cppshell::stream::object_unique_ptr output,
		cppshell::stream::object_unique_ptr error,
		cppshell::posix::process_id_unique_ptr,
		cppshell::process::optional_description const &);

	CPPSHELL_SYMBOL
	cppshell::stream::object_unique_ptr
	release_output();

	CPPSHELL_SYMBOL
	cppshell::stream::object_unique_ptr
	release_error();

	cppshell::posix::process_id_unique_ptr
	release_process_id();

	CPPSHELL_SYMBOL
	~object();
private:
	cppshell::context &context_;
	cppshell::stream::object_unique_ptr output_;
	cppshell::stream::object_unique_ptr error_;
	cppshell::posix::process_id_unique_ptr process_id_;
	cppshell::process::optional_description process_description_;
};
}
}

#endif

