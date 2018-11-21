AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(mod_zlib SHARED ${SRC_LIST} )
target_link_libraries(mod_zlib "langX")

target_link_libraries(mod_zlib "log4cpp")
#LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
target_link_libraries(mod_zlib "z")

SET_TARGET_PROPERTIES(mod_zlib PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_zlib" 
	SUFFIX ".so")


INSTALL(TARGETS mod_zlib
LIBRARY DESTINATION lib/langX
)