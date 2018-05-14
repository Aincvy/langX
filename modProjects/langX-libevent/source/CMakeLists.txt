AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(libevent SHARED ${SRC_LIST} )
target_link_libraries(libevent "langX")

target_link_libraries(libevent "log4cpp")
#LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
target_link_libraries(libevent "event")

SET_TARGET_PROPERTIES(libevent PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_libevent" 
	SUFFIX ".so")


INSTALL(TARGETS libevent
LIBRARY DESTINATION lib/langX
)