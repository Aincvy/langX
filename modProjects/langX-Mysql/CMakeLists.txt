cmake_minimum_required(VERSION 3.11)
SET(CMAKE_MODULE_PATH APPEND "${CMAKE_SOURCE_DIR}/../../cmake/")

PROJECT(LANGX_MYSQL)

find_package(MySQL REQUIRED)
find_package(langX REQUIRED)

include_directories(${MYSQL_INCLUDE_DIR})
include_directories(${langX_INCLUDE_DIR})

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_C_COMPILER       g++ )
SET(CMAKE_CXX_STANDARD 11)


ADD_SUBDIRECTORY(source target)
