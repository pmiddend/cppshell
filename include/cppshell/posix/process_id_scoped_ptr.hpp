#ifndef CPPSHELL_POSIX_PROCESS_ID_SCOPED_PTR_HPP_INCLUDED
#define CPPSHELL_POSIX_PROCESS_ID_SCOPED_PTR_HPP_INCLUDED

#include <cppshell/posix/process_id.hpp>
#include <fcppt/scoped_ptr.hpp>

namespace cppshell
{
namespace posix
{
typedef
fcppt::unique_ptr<cppshell::posix::process_id>
process_id_scoped_ptr;
}
}

#endif

