cmake_minimum_required(VERSION 3.11)
SET(CMAKE_MODULE_PATH APPEND "${CMAKE_SOURCE_DIR}/cmake/" )
SET(LOG4CPP_VERSION "NO-VERSION-INFO")

PROJECT(LANGX)
#ADD_SUBDIRECTORY(source bin)

#LINK_LIBRARIES(${Log4cpp_LIBRARIES})

set(CMAKE_BUILD_TYPE RelWithDebInfo)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_C_COMPILER       g++ )
ADD_DEFINITIONS(-std=c++11)

ADD_SUBDIRECTORY(source target)
#ADD_SUBDIRECTORY(extern bin)

# 配置文件安装
IF(NOT EXISTS /etc/langX/log4cpp.properties )
	INSTALL(FILES log4cpp.properties  DESTINATION /etc/langX )
ENDIF()

IF(NOT EXISTS /etc/langX/langX.properties )
	INSTALL(FILES langX.properties  DESTINATION /etc/langX )
ENDIF()

IF(NOT EXISTS /etc/langX/mods )
	INSTALL(DIRECTORY DESTINATION /etc/langX/mods)
ENDIF()