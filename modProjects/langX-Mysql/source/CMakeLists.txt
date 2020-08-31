AUX_SOURCE_DIRECTORY(. SRC_LIST)

link_directories("/usr/local/lib")
ADD_LIBRARY(mysql SHARED ${SRC_LIST} )
target_link_libraries(mysql "langX")

# LOG4CPP
FIND_PACKAGE(Log4cpp REQUIRED)
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(mysql ${Log4cpp_LIBRARY})


target_link_libraries(mysql ${MYSQL_LIB})

SET_TARGET_PROPERTIES(mysql PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mysql"
	SUFFIX ".so")


INSTALL(TARGETS mysql
LIBRARY DESTINATION lib/langX
)
