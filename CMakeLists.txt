cmake_minimum_required(VERSION 3.16)

project(dregx_LanguageProject
                      DESCRIPTION "Project for the language(s): dregx"
                      LANGUAGES CXX)

option(DREGX_ENABLE_COMPILER_GENERATOR "Enable Compiler Generation" OFF)
if (DREGX_ENABLE_COMPILER_GENERATOR)
	find_package(Deamer REQUIRED)
	add_subdirectory(CompilerGenerator)
endif()

add_subdirectory(dregx)
