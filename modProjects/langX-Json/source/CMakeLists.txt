FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(langX REQUIRED)


SET(SRC_LIST
		default.cpp
		JsonArray.cpp
		JsonModule.cpp
		JsonObject.cpp)

link_directories("/usr/local/lib")

ADD_LIBRARY(json SHARED ${SRC_LIST} )

#langx
INCLUDE_DIRECTORIES(${langX_INCLUDE_DIR})
target_link_libraries(json ${langX_LIBRARY})

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
