cmake_minimum_required(VERSION 3.11)
SET(CMAKE_MODULE_PATH APPEND "${CMAKE_SOURCE_DIR}/cmake/" )

# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
	cmake_policy(SET CMP0025 NEW)
endif ()

# log4cpp
SET(LOG4CPP_VERSION "NO-VERSION-INFO")
SET(Log4cpp_FIND_REQUIRED TRUE)

PROJECT(LANGX)

# SET(CMAKE_BUILD_TYPE RelWithDebInfo)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_C_COMPILER       g++ )
SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_LIST_DIR}/lib/tclap-include")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_LIST_DIR}/include")

# ADD_SUBDIRECTORY(include target)
ADD_SUBDIRECTORY(source target)


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

# 头文件安装
INSTALL(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/" # source directory
		DESTINATION "include/langX" # target directory
		FILES_MATCHING # install only matched files
		PATTERN "*.h" # select header files
		)