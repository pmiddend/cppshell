#ifndef CPPSHELL_MAKE_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_MAKE_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace cppshell
{
template
<
	typename T,
	typename... Args
>
std::unique_ptr<T>
make_unique(
	Args&&... args)
{
	return
		std::unique_ptr<T>(
			new T(
				std::forward<Args>(
					args)...));
}
}

#endif

