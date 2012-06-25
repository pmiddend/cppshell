#ifndef CPPSHELL_POSIX_PROCESS_ID_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_POSIX_PROCESS_ID_UNIQUE_PTR_HPP_INCLUDED

#include <cppshell/posix/process_id.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
namespace posix
{
typedef
std::unique_ptr<cppshell::posix::process_id>
process_id_unique_ptr;
}
}

#endif

