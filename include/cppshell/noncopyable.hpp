#ifndef CPPSHELL_NONCOPYABLE_HPP_INCLUDED
#define CPPSHELL_NONCOPYABLE_HPP_INCLUDED

#define CPPSHELL_NONCOPYABLE(c)\
	c(c const &) = delete;\
	c &operator=(c const &) = delete

#endif

