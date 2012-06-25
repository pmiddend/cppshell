#ifndef CPPSHELL_STRONG_FD_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_STRONG_FD_UNIQUE_PTR_HPP_INCLUDED

#include <cppshell/strong_fd_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
typedef
std::unique_ptr<cppshell::strong_fd>
strong_fd_unique_ptr;
}

#endif

