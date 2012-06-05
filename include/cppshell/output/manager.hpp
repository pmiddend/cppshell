#ifndef CPPSHELL_OUTPUT_MANAGER_HPP_INCLUDED
#define CPPSHELL_OUTPUT_MANAGER_HPP_INCLUDED

#include <cppshell/strong_fd_unique_ptr.hpp>
#include <cppshell/symbol.hpp>
#include <cppshell/linux/eventfd.hpp>
#include <cppshell/linux/epoll/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
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
	add_asynchronous_output(
		cppshell::strong_fd_unique_ptr);

	~manager();
private:
	cppshell::linux::eventfd cancel_event_;
	cppshell::linux::epoll::object epoll_object_;
	std::thread asynchronous_output_thread_;

	void
	asynchronous_output_thread();
};
}
}

#endif

