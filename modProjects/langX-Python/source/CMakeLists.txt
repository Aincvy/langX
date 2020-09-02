FIND_PACKAGE(Log4cpp REQUIRED)
AUX_SOURCE_DIRECTORY(. SRC_LIST)

link_directories("/usr/local/lib")

ADD_LIBRARY(python SHARED ${SRC_LIST} )
target_link_libraries(python "langX")
target_link_libraries(python "python3")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(python ${Log4cpp_LIBRARY})


SET_TARGET_PROPERTIES(python PROPERTIES
	PREFIX ""
	OUTPUT_NAME "python3_x"
	SUFFIX ".so")


INSTALL(TARGETS python
LIBRARY DESTINATION lib/langX
)
