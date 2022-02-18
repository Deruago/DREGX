cmake_minimum_required(VERSION 3.16)

project(dregx_LanguageProject
                      DESCRIPTION "Project for the language(s): dregx"
                      LANGUAGES CXX)

find_package(Deamer REQUIRED)

add_subdirectory(CompilerGenerator)
add_subdirectory(dregx)
