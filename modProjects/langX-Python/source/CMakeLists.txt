AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(python SHARED ${SRC_LIST} )
target_link_libraries(python "langX")

target_link_libraries(python "log4cpp")
#LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
target_link_libraries(python "python3")

SET_TARGET_PROPERTIES(python PROPERTIES
	PREFIX ""
	OUTPUT_NAME "python3_x" 
	SUFFIX ".so")


INSTALL(TARGETS python
LIBRARY DESTINATION lib/langX
)