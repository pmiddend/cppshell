#ifndef CPPSHELL_STRONG_FD_SHARED_PTR_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_SHARED_PTR_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <memory>


namespace cppshell
{
typedef
std::shared_ptr<cppshell::strong_fd>
strong_fd_shared_ptr;
}

#endif

