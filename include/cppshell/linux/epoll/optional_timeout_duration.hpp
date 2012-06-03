#ifndef CPPSHELL_LINUX_EPOLL_OPTIONAL_TIMEOUT_DURATION_HPP_INCLUDED
#define CPPSHELL_LINUX_EPOLL_OPTIONAL_TIMEOUT_DURATION_HPP_INCLUDED

#include <cppshell/linux/epoll/timeout_duration.hpp>
#include <fcppt/optional_fwd.hpp>

namespace cppshell
{
namespace linux
{
namespace epoll
{
typedef
fcppt::optional<cppshell::linux::epoll::timeout_duration>
optional_timeout_duration;
}
}
}

#endif

