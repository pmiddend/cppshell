cppshell
===================

cppshell, seriously?
-----------

Yeah, it sounds strange, I know. Let me motivate it a bit.

Shell languages have traditionally been designed with the following in mind:

- They're languages for both the command line prompt as well as scripts.
- They have to be *short* so you don't have to type as much in the command line.
- Being short usually means there are no *types*, so no *type safety* either.
- Also, no *complex data structures*. You've got numbers, strings and arrays, mostly.
- They're designed with certain "shortcuts" to operations you want to do very often. *Globbing* is an example of that (as in ls *.txt)
- There are a lot of facilities for *pipes*, *redirection* and *process management*.

cppshell, first of all, does *not* feature a command line. C++ is a language
where you have to type a lot. Also, it's usually compiled, which takes some
time, so it's just not an ideal candidate for an interpreter.

However, C++'s type safety and the RAII paradigm, as well as operator
overloading, does play well with certain aspects of shell programming. For
example, let's say we want to

- create a temporary file
- write to it
- pass it to a different program
- delete it

With bash, you could accomplish this using something like:

	filename=$(mkstemp)
	echo "lol" > $filename
	program $filename
	rm $filename

This is fine, as long as `program` doesn't crash and as long as you don't
forget the `rm` at the end. If either of the above happens, the temporary file
stays in `/tmp`, and you might not even notice it: Programs that crash don't
crash the script.

The RAII solution in C++ would, of course, be a temporary file class that
deletes the file in the destructor (warning, this is pseudo-code for now):

	cppshell::temporary_file file;
	cppshell::write_string(file,"lol");
	cppshell::execute_program(
		"program",
		cppshell::program_arguments{
			file.path()},
		cppshell::optional_input_fd{});

In the future, cppshell should wrap structures used for piping and process
execution, maybe even employing operator overloading, such as

	cppshell::execute_command(
		(cppshell::program("ls","foo") < "input_file.txt")
			| cppshell::program("grep","-r","lol"));

Is it portable?
---------------

Currently, it needs POSIX and Linux, mostly out of laziness.

What are the dependencies
-------------------------

A recent compiler (either gcc or clang), boost and fcppt.

Why C++11?
----------

Because it's well-supported on Linux and because I wanted to play with it.

What's this "fcppt" dependency, do you really need it?
------------------------------------------------------

fcppt is a valuable addition to C++11 and boost, featuring, amongst others,
strong typedefs. It's extremely portable and easy to install, so it shouldn't
be a problem.

Documentation
========

Using the "jit"
---------------

In bash, you can write script files just like normal text files, but with a
"shebang" line at the top, as such:

	#!/bin/bash

	echo "my script"

This is possible in cppshell, too, using the same syntax. Assuming the program
`cppshell_jit` is in your `$PATH`:

	#!/usr/bin/env cppshell_jit
	#include <iostream>

	int main()
	{
		std::cout << "my script\n";
	}

You could store this file as `test.cpp` and give it executable permissions (via
`chmod +x test.cpp`) and it's runnable.

cppshell will read the configuration file to determine the compiler of your
choice (if no configuration exists, it will look for g++ in your `$PATH`) and
compile the file. If errors occur, those will be printed. If no errors occur,
the program will be executed. The configuration file resides in
`$XDG_CONFIG_HOME/cppshell/config.ini` and has a very simple format. Set your
preferred compiler using:

	compiler=/usr/bin/clang++

Arguments can be passed to the script. They will be forwarded to the script as
arguments to `main`:

	#!/usr/bin/env cppshell_jit
	#include <iostream>

	int main(
		int argc,
		char *argv[])
	{
		std::cout << "=> Hi, " << argv[1] << "!\n";
	}

Will result in:

	./test.cpp Philipp
	=> Hi, Philipp!

If you need additional libraries or compilerflags in your script, you can pass
those to the cppshell_jit program, too:

	#!/usr/bin/env cppshell_jit -lSDL
	#include <iostream>
	#include <SDL.h>

	int main()
	{
		SDL_Init(SDL_INIT_VIDEO);
	}


In the future, there'll be a cache, so scripts will be compiled only once. This
is not implemented, yet (see issue gh-1).

Also, default cflags and lflags should be configurable via configuration file
(see issue gh-2).
