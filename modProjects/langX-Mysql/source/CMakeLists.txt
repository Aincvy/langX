
SET(SRC_LIST
		DataRow.cpp
		DataTable.cpp
		MysqlClient.cpp
		MysqlModule.cpp)

link_directories("/usr/local/lib")
ADD_LIBRARY(mysql SHARED ${SRC_LIST} )
target_link_libraries(mysql "langX")

# LOG4CPP
FIND_PACKAGE(Log4cpp REQUIRED)
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(mysql ${Log4cpp_LIBRARY})

# langX
target_link_libraries(mysql ${langX_LIBRARY})

# mysql
target_link_libraries(mysql ${MYSQL_LIB})

SET_TARGET_PROPERTIES(mysql PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mysql"
	SUFFIX ".so")


INSTALL(TARGETS mysql
LIBRARY DESTINATION lib/langX
)
