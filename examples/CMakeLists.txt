add_definitions(
	"${CPPSHELL_CONFIG_LINK_MACROS}")

add_executable(
	simple
	simple.cpp)

target_link_libraries(
	simple
	${CPPSHELL_DEFAULT_LINK_TARGET})
