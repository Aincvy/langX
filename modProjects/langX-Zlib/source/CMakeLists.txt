FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(langX REQUIRED)

SET(SRC_LIST
		Zip.cpp
		ZipFile.cpp
		Zlib.cpp
		ZlibModule.cpp)

link_directories("/usr/local/lib")
ADD_LIBRARY(mod_zlib SHARED ${SRC_LIST} )

target_link_libraries(mod_zlib "z")

#langX
INCLUDE_DIRECTORIES(${langX_INCLUDE_DIR})
target_link_libraries(mod_zlib ${langX_LIBRARY})

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(mod_zlib ${Log4cpp_LIBRARY})

SET_TARGET_PROPERTIES(mod_zlib PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_zlib"
	SUFFIX ".so")


INSTALL(TARGETS mod_zlib
LIBRARY DESTINATION lib/langX
)
