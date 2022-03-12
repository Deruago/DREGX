cmake_minimum_required(VERSION 3.16)

project(dregx_LanguageProject
                      DESCRIPTION "Project for the language(s): dregx"
                      LANGUAGES CXX)

option(dregx_ENABLE_COMPILER_GENERATOR "Enable Compiler Generation" ON)
if (dregx_ENABLE_COMPILER_GENERATOR)
	find_package(Deamer REQUIRED)
	add_subdirectory(CompilerGenerator)
endif()

add_subdirectory(dregx)
