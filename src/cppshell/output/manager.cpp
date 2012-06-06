#include <cppshell/check_unix_command_error.hpp>
#include <cppshell/strong_fd.hpp>
#include <cppshell/output/manager.hpp>
#include <fcppt/cref.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>


cppshell::output::manager::manager()
:
	cancel_event_{
		static_cast<cppshell::linux::eventfd::initial_value_type>(
			0)},
	fd_to_thread_data_{}
{
}

void
cppshell::output::manager::add_asynchronous_redirection(
	cppshell::strong_fd_unique_ptr _asynchronous_fd,
	cppshell::output::redirection_target const &_redirection_target)
{
	fd_to_thread_data_map::iterator it =
		fd_to_thread_data_.find(
			_redirection_target.get());

	if(it == fd_to_thread_data_.end())
	{
		it =
			fcppt::container::ptr::insert_unique_ptr_map(
				fd_to_thread_data_,
				_redirection_target.get(),
				fcppt::make_unique_ptr<cppshell::output::thread_data>(
					_redirection_target,
					fcppt::cref(
						cancel_event_))).first;
	}

	it->second->add(
		fcppt::move(
			_asynchronous_fd));
}

cppshell::output::manager::~manager()
{
	cancel_event_.add(
		1u);
}
