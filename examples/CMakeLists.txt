add_definitions(
	"${CPPSHELL_CONFIG_LINK_MACROS}")

add_executable(
	sort_lines
	sort_lines.cpp)

target_link_libraries(
	sort_lines
	${CPPSHELL_DEFAULT_LINK_TARGET})

add_executable(
	execute_command
	execute_command.cpp)

target_link_libraries(
	execute_command
	${CPPSHELL_DEFAULT_LINK_TARGET})

add_executable(
	stream_test
	stream_test.cpp)

target_link_libraries(
	stream_test
	${CPPSHELL_DEFAULT_LINK_TARGET})

add_executable(
	tempfile_test
	tempfile.cpp)

target_link_libraries(
	tempfile_test
	${CPPSHELL_DEFAULT_LINK_TARGET})
