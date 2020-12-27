FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(langX REQUIRED)

SET(SRC_LIST
		PyException.cpp
		PyObject.cpp
		PyObjectEasy.cpp
		PyObjectType.cpp
		PySomeFunction.cpp
		PythonHook.cpp
		PythonLib.cpp
		PythonModule.cpp
		pyModule/PyDateTime.cpp
)


ADD_LIBRARY(python SHARED ${SRC_LIST})

# langX
INCLUDE_DIRECTORIES(python ${langX_INCLUDE_DIR})
target_link_libraries(python ${langX_LIBRARY})

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(python ${Log4cpp_LIBRARY})

# python 3
find_package (Python3 COMPONENTS Interpreter Development)
MESSAGE("Python3_FOUND: ${Python3_FOUND}")
MESSAGE("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
MESSAGE("Python3_LIBRARIES: ${Python3_LIBRARIES}")
INCLUDE_DIRECTORIES(${Python3_INCLUDE_DIRS})
target_link_libraries(python ${Python3_LIBRARIES})


SET_TARGET_PROPERTIES(python PROPERTIES
	PREFIX ""
	OUTPUT_NAME "python3_x"
	SUFFIX ".so")


INSTALL(TARGETS python
LIBRARY DESTINATION lib/langX
)
