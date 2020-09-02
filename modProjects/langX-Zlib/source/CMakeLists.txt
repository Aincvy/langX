FIND_PACKAGE(Log4cpp REQUIRED)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

link_directories("/usr/local/lib")
ADD_LIBRARY(mod_zlib SHARED ${SRC_LIST} )
target_link_libraries(mod_zlib "langX")

target_link_libraries(mod_zlib "z")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(mod_zlib ${Log4cpp_LIBRARY})

SET_TARGET_PROPERTIES(mod_zlib PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_zlib"
	SUFFIX ".so")


INSTALL(TARGETS mod_zlib
LIBRARY DESTINATION lib/langX
)
