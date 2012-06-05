#ifndef CPPSHELL_STRONG_FD_SCOPED_PTR_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_SCOPED_PTR_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>


namespace cppshell
{
typedef
fcppt::scoped_ptr<cppshell::strong_fd>
strong_fd_scoped_ptr;
}

#endif

