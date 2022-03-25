# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject
#
# This file is part of the directory: lib

# All source and header files of this project.
file(GLOB_RECURSE SOURCE_LIST "${dregx_SOURCE_DIR}/lib/*.cpp")
file(GLOB_RECURSE HEADER_LIST "${dregx_SOURCE_DIR}/include/*.h")

# Root library extension
dregx_root_library_extend("dregx" "${dregx_SOURCE_DIR}/extern" "${dregx_SOURCE_DIR}/include" "${SOURCE_LIST}")

