AUX_SOURCE_DIRECTORY(. SRC_LIST)

ADD_LIBRARY(mysql SHARED ${SRC_LIST} )
target_link_libraries(mysql "langX")

target_link_libraries(mysql "log4cpp")
#LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
#target_link_libraries(mysql "mysqlclient")
target_link_libraries(mysql ${MYSQL_LIB})

SET_TARGET_PROPERTIES(mysql PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mysql" 
	SUFFIX ".so")


INSTALL(TARGETS mysql
LIBRARY DESTINATION lib/langX
)