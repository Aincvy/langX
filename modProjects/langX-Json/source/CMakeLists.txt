AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(json SHARED ${SRC_LIST} )
target_link_libraries(json "langX")

target_link_libraries(json "log4cpp")
target_link_libraries(json "cjson")
#LINK_LIBRARIES(${LOG4CPP_LIBRARIES})

SET_TARGET_PROPERTIES(json PROPERTIES
	PREFIX ""
	OUTPUT_NAME "json" 
	SUFFIX ".so")


INSTALL(TARGETS json
LIBRARY DESTINATION lib/langX
)