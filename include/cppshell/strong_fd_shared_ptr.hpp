#ifndef CPPSHELL_STRONG_FD_SHARED_PTR_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_SHARED_PTR_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <fcppt/shared_ptr.hpp>


namespace cppshell
{
typedef
fcppt::shared_ptr<cppshell::strong_fd>
strong_fd_shared_ptr;
}

#endif

