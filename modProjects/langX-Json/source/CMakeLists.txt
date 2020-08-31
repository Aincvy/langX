FIND_PACKAGE(Log4cpp REQUIRED)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

link_directories("/usr/local/lib")
ADD_LIBRARY(json SHARED ${SRC_LIST} )
target_link_libraries(json "langX")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(json ${Log4cpp_LIBRARY})


target_link_libraries(json "cjson")


SET_TARGET_PROPERTIES(json PROPERTIES
	PREFIX ""
	OUTPUT_NAME "json"
	SUFFIX ".so")


INSTALL(TARGETS json
LIBRARY DESTINATION lib/langX
)
