FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(langX REQUIRED)


SET(SRC_LIST
		Application.cpp
		ByteArray.cpp
		Convert.cpp
		CoreModule.cpp
		File.cpp
		FileStream.cpp
		Iterator.cpp
		Matcher.cpp
		Math.cpp
		Pattern.cpp
		Random.cpp
		Stream.cpp
		StringBuilder.cpp
		Thread.cpp
		default/TimeSpan.cpp
		default/DateTime.cpp
		default/Default.cpp
		collection/Queue.cpp
		collection/Set.cpp
		collection/Stack.cpp
		collection/List.cpp
		collection/Map.cpp
		collection/Vector.cpp
		)

ADD_LIBRARY(core SHARED ${SRC_LIST})

#langX
target_link_libraries(core ${langX_LIBRARY})
INCLUDE_DIRECTORIES(core ${langX_INCLUDE_DIR})

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(core ${Log4cpp_LIBRARY})

SET_TARGET_PROPERTIES(core PROPERTIES
	PREFIX ""
	OUTPUT_NAME "core"
	SUFFIX ".so")


INSTALL(TARGETS core
LIBRARY DESTINATION lib/langX
)
