#ifndef CPPSHELL_STRONG_FD_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_UNIQUE_PTR_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <fcppt/unique_ptr.hpp>


namespace cppshell
{
typedef
fcppt::unique_ptr<cppshell::strong_fd>
strong_fd_unique_ptr;
}

#endif

