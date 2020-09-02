FIND_PACKAGE(Log4cpp REQUIRED)

AUX_SOURCE_DIRECTORY(. SRC_LIST)


link_directories("/usr/local/lib")
ADD_LIBRARY(targetLib SHARED ${SRC_LIST} )
target_link_libraries(targetLib "langX")
target_link_libraries(targetLib "hiredis")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(targetLib ${Log4cpp_LIBRARY})

SET_TARGET_PROPERTIES(targetLib PROPERTIES
	PREFIX ""
	OUTPUT_NAME "redis"
	SUFFIX ".so")


INSTALL(TARGETS targetLib
LIBRARY DESTINATION lib/langX
)
