cmake_minimum_required(VERSION 3.16)

project(dregx VERSION 0.1.0)

include(GNUInstallDirs)

find_package(Deamer_External REQUIRED)
find_package(Deamer_Algorithm REQUIRED)

include(deamer.cmake)
include(cmake/deamer_dregx_specialized.cmake)

add_subdirectory(extern)
add_subdirectory(lib)

option(DREGX_DEBUG "Debug Build" OFF)

if(DREGX_DEBUG)

else()
	if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set_target_properties(dregx PROPERTIES COMPILE_FLAGS "-O3")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set_target_properties(dregx PROPERTIES COMPILE_FLAGS "-O3")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set_target_properties(dregx PROPERTIES COMPILE_FLAGS "/O3")
	endif()
endif()

option(DREGX_TESTS "Enables all the tests" OFF)
if(DREGX_TESTS)
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

# Package

include(CMakePackageConfigHelpers)

configure_package_config_file(${dregx_SOURCE_DIR}/cmake/dregxConfig.cmake.in
  "${dregx_BINARY_DIR}/dregxConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dregx
)

write_basic_package_version_file(
	"dregxConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(FILES
	${dregx_BINARY_DIR}/dregxConfig.cmake
	${dregx_BINARY_DIR}/dregxConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dregx
)