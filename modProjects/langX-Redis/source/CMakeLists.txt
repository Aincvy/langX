AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(targetLib SHARED ${SRC_LIST} )
target_link_libraries(targetLib "langX")
target_link_libraries(targetLib "log4cpp")
target_link_libraries(targetLib "hiredis")

SET_TARGET_PROPERTIES(targetLib PROPERTIES
	PREFIX ""
	OUTPUT_NAME "redis" 
	SUFFIX ".so")


INSTALL(TARGETS targetLib
LIBRARY DESTINATION lib/langX
)