FIND_PACKAGE(Log4cpp REQUIRED)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

link_directories("/usr/local/lib")
ADD_LIBRARY(core SHARED ${SRC_LIST} )
target_link_libraries(core "langX")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(core ${Log4cpp_LIBRARY})

SET_TARGET_PROPERTIES(core PROPERTIES
	PREFIX ""
	OUTPUT_NAME "core"
	SUFFIX ".so")


INSTALL(TARGETS core
LIBRARY DESTINATION lib/langX
)
