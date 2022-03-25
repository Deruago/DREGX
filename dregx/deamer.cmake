# This file is auto-generated and auto-maintained.
# Please don't change code in this file, as new changes will be discarded,
# when Deamer regenerates the project.
#
# If you want to contribute to Deamer.
# Please visit: https://github.com/Deruago/theDeamerProject 

include(GNUInstallDirs)





add_library(dregx STATIC)
target_compile_features(dregx PUBLIC cxx_std_17)
set_target_properties(dregx PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(dregx PUBLIC 
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(dregx PRIVATE Deamer::External Deamer::Algorithm)


function(dregx_root_library_extend projectname extern_directory include_directory source_files)
	target_sources(dregx PRIVATE ${source_files})

	target_include_directories(dregx PUBLIC 
		$<BUILD_INTERFACE:${include_directory}>
		$<BUILD_INTERFACE:${extern_directory}>
	)
endfunction()


add_library(deamer_reserved_dregx_core_library ALIAS dregx)

function(dregx_add_external_library external_library_name source_files)
	target_sources(dregx PRIVATE ${source_files})
endfunction()




