# Alias Target
add_library(Deamer::dregx ALIAS dregx)

# Install Targets

install(TARGETS dregx
    EXPORT dregx_Exports
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/dregx"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}/dregx"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}/dregx"
    )

export(TARGETS
	dregx
    NAMESPACE Deamer::
	FILE "${CMAKE_CURRENT_BINARY_DIR}/dregx_Exports.cmake"
)

install(EXPORT
	dregx_Exports
    NAMESPACE Deamer::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/dregx"
)

# Install Headers

install(DIRECTORY ${dregx_SOURCE_DIR}/include/Deamer
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "LICENSE"
    )

install(DIRECTORY ${dregx_SOURCE_DIR}/include/dregx
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "LICENSE"
    )
