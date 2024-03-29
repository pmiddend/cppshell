#ifndef CPPSHELL_COMMAND_OUTPUT_OBJECT_HPP_INCLUDED
#define CPPSHELL_COMMAND_OUTPUT_OBJECT_HPP_INCLUDED

#include <cppshell/context_fwd.hpp>
#include <cppshell/noncopyable.hpp>
#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/posix/process_id_unique_ptr.hpp>
#include <cppshell/process/optional_description.hpp>
#include <fcppt/optional.hpp>


namespace cppshell
{
namespace command_output
{
class object
{
CPPSHELL_NONCOPYABLE(
	object);
public:
	CPPSHELL_SYMBOL
	object(
		cppshell::context &,
		cppshell::strong_fd_unique_ptr output,
		cppshell::strong_fd_unique_ptr error,
		cppshell::posix::process_id_unique_ptr,
		cppshell::process::optional_description const &);

	CPPSHELL_SYMBOL
	cppshell::strong_fd_unique_ptr
	release_output();

	CPPSHELL_SYMBOL
	cppshell::strong_fd_unique_ptr
	release_error();

	CPPSHELL_SYMBOL
	cppshell::posix::process_id_unique_ptr
	release_process_id();

	CPPSHELL_SYMBOL
	~object();
private:
	cppshell::context &context_;
	cppshell::strong_fd_unique_ptr output_;
	cppshell::strong_fd_unique_ptr error_;
	cppshell::posix::process_id_unique_ptr process_id_;
	cppshell::process::optional_description process_description_;
};
}
}

#endif

