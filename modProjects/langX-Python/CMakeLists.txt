cmake_minimum_required(VERSION 3.13)
SET(CMAKE_MODULE_PATH APPEND "${CMAKE_SOURCE_DIR}/../../cmake/" )

PROJECT(LANGX_PYTHON)

#SET(CMAKE_BUILD_TYPE RelWithDebInfo)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_C_COMPILER       g++ )
SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_LIST_DIR}/include")

ADD_SUBDIRECTORY(source target)
