cmake_minimum_required(VERSION 3.16)

project(dregx)

find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)

include(deamer.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

option(TESTS "Enables all the tests" ON)
if(TESTS)
	message(STATUS "Tests are now available.")
	find_package(GTest)
	if (GTEST_FOUND)
		enable_testing()
		add_subdirectory(tests)
	else()
		enable_testing()
		include(GoogleTest)
		add_subdirectory(tests)
	endif()
endif()

option(APPLICATIONS "Enables all the applications" ON)
if(APPLICATIONS)
	message(STATUS "Applications are now available.")
	add_subdirectory(sources)
endif()


add_executable(dregx_console main.cpp)
target_link_libraries(dregx_console dregx_static_library)
