# 将当前文件夹下的所有文件 放到一个变量里面

# find flex yacc lib
FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(Log4cpp REQUIRED)

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})

MESSAGE(STATUS "FIND LOG4CPP IN ${Log4cpp_LIBRARY}") 

AUX_SOURCE_DIRECTORY(. SRC_LIST)
FILE(GLOB EXT_FILES "../extern/*.c")
FILE(GLOB EXTEND_CLASS "extend/*.cpp")
ADD_LIBRARY(liblangX.so SHARED ${SRC_LIST} ${EXT_FILES} ${EXTEND_CLASS})
target_link_libraries(liblangX.so "log4cpp")
target_link_libraries(liblangX.so "l")
target_link_libraries(liblangX.so "dl")
target_link_libraries(liblangX.so "pthread")
LINK_LIBRARIES(${LOG4CPP_LIBRARIES})
SET_TARGET_PROPERTIES(liblangX.so PROPERTIES OUTPUT_NAME "langX")

#LINK_LIBRARIES(${FLEX_LIBRARIES})
#MESSAGE(STATUS "FIND flex: ${FLEX_EXECUTABLE}") 

add_executable(langX ${EXT_FILES})
set_property(TARGET liblangX.so PROPERTY INTERFACE_CUSTOM_PROP ON)
target_link_libraries(langX liblangX.so)

INSTALL(TARGETS liblangX.so langX
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
)
