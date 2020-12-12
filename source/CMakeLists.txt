# 将当前文件夹下的所有文件 放到一个变量里面

# find flex yacc lib
FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(Log4cpp REQUIRED)

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})

MESSAGE(STATUS "OS is ${CMAKE_SYSTEM}")
MESSAGE(STATUS "FIND LOG4CPP IN ${Log4cpp_LIBRARY}")
MESSAGE(STATUS "FLEX STATUS ${FLEX_LIBRARIES}")

SET( SRC_LIST
		Allocator.cpp
		ClassInfo.cpp
		Config.cpp
		Environment.cpp
		Exception.cpp
		ExecNode.cpp
		Function.cpp
        langX.cpp
		langXObject.cpp
		langXrtlib.cpp
		langXThread.cpp
		LogManager.cpp
		NullObject.cpp
		Number.cpp
		Object.cpp
		Program.cpp
		RegFunctions.cpp
		RegObjects.cpp
		StackTrace.cpp
		StringType.cpp
		Utils.cpp
		X3rdModule.cpp
		XArray.cpp
		XNameSpace.cpp
		NodeCreator.cpp
		TypeHelper.cpp
		extend/langXLogger.cpp
		extend/langXString.cpp
		node/ExecBaseMathNode.cpp
		node/ExecAssignNode.cpp
		node/ExecLogicNode.cpp
		node/ExecOOPNode.cpp
        )

FILE(GLOB EXT_FILES "${CMAKE_CURRENT_LIST_DIR}/../extern/*.c")
ADD_LIBRARY(liblangX.so SHARED ${SRC_LIST} ${EXT_FILES})

TARGET_LINK_LIBRARIES(liblangX.so ${Log4cpp_LIBRARY})
TARGET_LINK_LIBRARIES(liblangX.so "dl")
TARGET_LINK_LIBRARIES(liblangX.so "pthread")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	TARGET_LINK_LIBRARIES(liblangX.so ${FLEX_LIBRARIES})
ELSE ()
	TARGET_LINK_LIBRARIES(liblangX.so "l")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
SET_TARGET_PROPERTIES(liblangX.so PROPERTIES OUTPUT_NAME "langX")


add_executable(langX ${EXT_FILES})
set_property(TARGET liblangX.so PROPERTY INTERFACE_CUSTOM_PROP ON)
target_link_libraries(langX liblangX.so)

INSTALL(TARGETS liblangX.so langX
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
)
