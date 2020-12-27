FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(langX REQUIRED)

SET(SRC_LIST
		RedisClient.cpp
		RedisExceptions.cpp
		RedisModule.cpp)


link_directories("/usr/local/lib")
ADD_LIBRARY(targetLib SHARED ${SRC_LIST} )

target_link_libraries(targetLib "hiredis")

#langX
INCLUDE_DIRECTORIES(${langX_INCLUDE_DIR})
target_link_libraries(targetLib ${langX_LIBRARY})

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
