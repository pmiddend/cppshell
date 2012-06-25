cmake_minimum_required(
	VERSION
	2.8)

project(
	cppshell)

include(
	FcpptCMakeUtils)

include(
	FcpptSymbol)

find_package(
	Boost 1.45.0 REQUIRED COMPONENTS
	system
	chrono
	program_options)

include_directories(
	${Boost_INCLUDE_DIR})
link_directories(
	${Boost_LIBRARY_DIRS})
# boost end

# fcppt begin
find_package(
	Fcppt REQUIRED)
include_directories(
	${Fcppt_INCLUDE_DIRS})
add_definitions(
	${Fcppt_DEFINITIONS})
# fcppt end

# get rid of a pretty useless warning
if(CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP)
	add_definitions(
		-Wno-old-style-cast)
endif()

add_definitions(
	-std=c++0x)

include_directories(
	${CMAKE_SOURCE_DIR}/include)

include_directories(
	${CMAKE_BINARY_DIR}/include)

set(
	CPPSHELL_FILES
	src/cppshell/cache_directory.cpp
	src/cppshell/check_unix_command_error.cpp
	src/cppshell/command_arguments_from_string.cpp
	src/cppshell/command_output/object.cpp
	src/cppshell/config_directory.cpp
	src/cppshell/context.cpp
	src/cppshell/execute_command.cpp
	src/cppshell/fd_to_ostream.cpp
	src/cppshell/file_contents_if_exists.cpp
	src/cppshell/getenv.cpp
	src/cppshell/home_directory.cpp
	src/cppshell/linux/epoll/object.cpp
	src/cppshell/linux/eventfd.cpp
	src/cppshell/output/manager.cpp
	src/cppshell/output/thread_data.cpp
	src/cppshell/path_for_executable.cpp
	src/cppshell/posix/chmod_fd.cpp
	src/cppshell/posix/exec.cpp
	src/cppshell/posix/fork.cpp
	src/cppshell/posix/open.cpp
	src/cppshell/posix/open_flags_to_posix_flags.cpp
	src/cppshell/posix/permissions/group_execute.cpp
	src/cppshell/posix/permissions/group_read.cpp
	src/cppshell/posix/permissions/group_write.cpp
	src/cppshell/posix/permissions/others_execute.cpp
	src/cppshell/posix/permissions/others_read.cpp
	src/cppshell/posix/permissions/others_write.cpp
	src/cppshell/posix/permissions/owner_execute.cpp
	src/cppshell/posix/permissions/owner_read.cpp
	src/cppshell/posix/permissions/owner_write.cpp
	src/cppshell/posix/permissions/set_group_id.cpp
	src/cppshell/posix/permissions/set_user_id.cpp
	src/cppshell/posix/permissions/sticky.cpp
	src/cppshell/posix/pipe.cpp
	src/cppshell/posix/redirect_stderr_to_stdout.cpp
	src/cppshell/posix/redirect_to_fd.cpp
	src/cppshell/posix/stderr_fd.cpp
	src/cppshell/posix/stdin_fd.cpp
	src/cppshell/posix/stdout_fd.cpp
	src/cppshell/posix/temporary_file.cpp
	src/cppshell/posix/wait_for_process.cpp
	src/cppshell/process/data.cpp
	src/cppshell/process/manager.cpp
	src/cppshell/strong_fd.cpp
	src/cppshell/warning_stream.cpp
)

fcppt_generate_symbol_header(
	CPPSHELL_STATIC_LINK
	cppshell
	CPPSHELL
	cppshell)

option(
	ENABLE_SHARED
	"Build cppshell as a shared library"
	TRUE)

option(
	ENABLE_STATIC
	"Build cppshell as a static library"
	FALSE)


if(
	NOT ENABLE_SHARED AND NOT ENABLE_STATIC)
	message(
		FATAL_ERROR
		"You disabled both STATIC and SHARED")
endif()

# choose a library to link the tests to
if(
	ENABLE_SHARED)
	set(
		CPPSHELL_DEFAULT_LINK_TARGET
		cppshell)
endif()

# static overrides shared
if(
	ENABLE_STATIC)
	set(
		CPPSHELL_DEFAULT_LINK_TARGET
		cppshell_static)

	set(
		CPPSHELL_CONFIG_LINK_MACROS
		"-D CPPSHELL_STATIC_LINK")
endif()

function(
	MAKE_CPPSHELL_LIBRARY
	TARGETNAME
	VARIANT)
	add_library(
		${TARGETNAME}
		${VARIANT}
		${CPPSHELL_FILES})

	target_link_libraries(
		${TARGETNAME}
		${Boost_SYSTEM_LIBRARY})

	if(
		${VARIANT} STREQUAL "STATIC")
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			COMPILE_DEFINITIONS
			"CPPSHELL_STATIC_LINK")
	endif()

        if(
                ${VARIANT} STREQUAL "STATIC")
                set_target_properties(
                        ${TARGETNAME}
                        PROPERTIES
                        COMPILE_DEFINITIONS
                        "CPPSHELL_STATIC_LINK")
        endif()

	target_link_libraries(
		${TARGETNAME}
		${Fcppt_core_LIBRARIES}
		${Fcppt_filesystem_LIBRARIES}
		${Boost_LIBRARIES})

	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		${INSTALL_LIBRARY_DIR})
endfunction()

if(
	ENABLE_STATIC
)
	make_cppshell_library(
		cppshell_static
		STATIC)
endif()

if(
	ENABLE_SHARED
)
	make_cppshell_library(
		cppshell
		SHARED)
endif()

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON)

if(ENABLE_EXAMPLES)
	add_subdirectory(
		examples)
endif()

option(
	ENABLE_TOOLS
	"Build the tools"
	ON)

if(ENABLE_TOOLS)
	add_subdirectory(
		tools)
endif()
