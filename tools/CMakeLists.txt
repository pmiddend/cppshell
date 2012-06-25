add_definitions(
	"${CPPSHELL_CONFIG_LINK_MACROS}")

add_executable(
	cppshell_jit
	cppshell_jit.cpp)

target_link_libraries(
	cppshell_jit
	${CPPSHELL_DEFAULT_LINK_TARGET})
