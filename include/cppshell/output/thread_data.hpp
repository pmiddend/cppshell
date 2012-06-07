#ifndef CPPSHELL_OUTPUT_THREAD_DATA_HPP_INCLUDED
#define CPPSHELL_OUTPUT_THREAD_DATA_HPP_INCLUDED

#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/linux/eventfd_fwd.hpp>
#include <cppshell/linux/epoll/object.hpp>
#include <cppshell/output/redirection_target.hpp>
#include <cppshell/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <thread>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace output
{
class thread_data
{
CPPSHELL_NONCOPYABLE(
	thread_data);
public:
	CPPSHELL_SYMBOL
	explicit
	thread_data(
		cppshell::output::redirection_target const &,
		cppshell::linux::eventfd const &cancel_fd);

	thread_data(
		thread_data &&);

	void
	add(
		cppshell::strong_fd_unique_ptr);

	CPPSHELL_SYMBOL
	~thread_data();
private:
	cppshell::linux::epoll::object epoll_object_;
	std::thread asynchronous_output_thread_;

	void
	asynchronous_output_thread(
		cppshell::output::redirection_target const &,
		cppshell::linux::eventfd const &);
};
}
}

#endif

