FIND_PACKAGE(Log4cpp REQUIRED)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

include_directories("/usr/local/include")

link_directories("/usr/local/lib")

ADD_LIBRARY(libevent SHARED ${SRC_LIST} )

target_link_libraries(libevent "langX")
target_link_libraries(libevent "event")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(libevent ${Log4cpp_LIBRARY})


SET_TARGET_PROPERTIES(libevent PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_libevent"
	SUFFIX ".so")


INSTALL(TARGETS libevent
LIBRARY DESTINATION lib/langX
)
