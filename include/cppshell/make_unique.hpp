#ifndef CPPSHELL_MAKE_UNIQUE_PTR_HPP_INCLUDED
#define CPPSHELL_MAKE_UNIQUE_PTR_HPP_INCLUDED

#include <memory>
#include <utility>

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

