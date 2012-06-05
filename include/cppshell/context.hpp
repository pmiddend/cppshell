#ifndef CPPSHELL_CONTEXT_HPP_INCLUDED
#define CPPSHELL_CONTEXT_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <cppshell/linux/eventfd.hpp>
#include <cppshell/linux/epoll/object.hpp>
#include <cppshell/posix/process_id.hpp>
#include <cppshell/process/wait_for_completion.hpp>
#include <cppshell/process/manager.hpp>
#include <cppshell/stream/object_unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <thread>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
class context
{
FCPPT_NONCOPYABLE(
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
	void
	add_asynchronous_output(
		cppshell::stream::object_unique_ptr);

	CPPSHELL_SYMBOL
	~context();
private:
	cppshell::process::manager process_manager_;
	cppshell::linux::eventfd cancel_event_;
	cppshell::linux::epoll::object epoll_object_;
	std::thread asynchronous_output_thread_;

	void
	asynchronous_output_thread();
};
}

#endif

