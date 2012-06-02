#ifndef CPPSHELL_STREAM_OBJECT_HPP_INCLUDED
#define CPPSHELL_STREAM_OBJECT_HPP_INCLUDED

#include <cppshell/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace cppshell
{
namespace stream
{
class object
{
public:
	CPPSHELL_SYMBOL
	explicit
	object(
		int);

	CPPSHELL_SYMBOL
	int
	fd() const;

	CPPSHELL_SYMBOL
	~object();
private:
	int const fd_;
};
}
}

#endif

