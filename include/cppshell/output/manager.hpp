#ifndef CPPSHELL_OUTPUT_MANAGER_HPP_INCLUDED
#define CPPSHELL_OUTPUT_MANAGER_HPP_INCLUDED

#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/linux/eventfd.hpp>
#include <cppshell/linux/epoll/object.hpp>
#include <cppshell/output/redirection_target.hpp>
#include <cppshell/output/thread_data.hpp>
#include <cppshell/posix/fd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <thread>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace output
{
class manager
{
FCPPT_NONCOPYABLE(
	manager);
public:
	CPPSHELL_SYMBOL
	manager();

	CPPSHELL_SYMBOL
	void
	add_asynchronous_redirection(
		cppshell::strong_fd_unique_ptr,
		cppshell::output::redirection_target const &);

	~manager();
private:
	typedef
	boost::ptr_map
	<
		cppshell::posix::fd,
		cppshell::output::thread_data
	>
	fd_to_thread_data_map;

	cppshell::linux::eventfd cancel_event_;
	fd_to_thread_data_map fd_to_thread_data_;
};
}
}

#endif

