cmake_minimum_required(VERSION 3.16)

project(dregx_CompilerGenerator
                      DESCRIPTION "Compiler/Ecosystem generator for language(s): dregx. This CompilerGenerator project uses Deamer CC for the generation, and DLDL to generate the definitions."
                      LANGUAGES CXX)

find_package(Deamer REQUIRED)

file(GLOB_RECURSE SOURCE_LIST "${dregx_CompilerGenerator_SOURCE_DIR}/lib/*.cpp")

add_library(dregx_CompilerGenerator_implementation_detail STATIC)
target_sources(dregx_CompilerGenerator_implementation_detail PRIVATE ${SOURCE_LIST})

target_include_directories(dregx_CompilerGenerator_implementation_detail PUBLIC "${dregx_CompilerGenerator_SOURCE_DIR}/include")
target_link_libraries(dregx_CompilerGenerator_implementation_detail PRIVATE Deamer::Deamer)
target_compile_features(dregx_CompilerGenerator_implementation_detail PUBLIC cxx_std_17)
set_target_properties(dregx_CompilerGenerator_implementation_detail PROPERTIES LINKER_LANGUAGE CXX)

add_executable(dregx_CompilerGenerator_Main)
target_sources(dregx_CompilerGenerator_Main PRIVATE "${dregx_CompilerGenerator_SOURCE_DIR}/main.cpp")
target_link_libraries(dregx_CompilerGenerator_Main PRIVATE dregx_CompilerGenerator_implementation_detail)
