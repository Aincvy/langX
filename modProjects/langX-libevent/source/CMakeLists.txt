FIND_PACKAGE(Log4cpp REQUIRED)

link_directories("/usr/local/lib")

SET(SRC_LIST
		BytesDecoder.cpp
		BytesEncoder.cpp
		DefaultBytesDecoder.cpp
		DefaultBytesEncoder.cpp
		DefaultNetPacket.cpp
		DefaultNetPacketX.cpp
		HttpRequest.cpp
		HttpResponse.cpp
		HttpServer.cpp
		HttpServerRoute.cpp
		libeventModule.cpp
		TcpClient.cpp
		TcpServer.cpp
		TimerEvent.cpp EventBase.cpp)

ADD_LIBRARY(libevent SHARED ${SRC_LIST} TimerEvent.cpp)

target_link_libraries(libevent "langX")
target_link_libraries(libevent "event")

# LOG4CPP
INCLUDE_DIRECTORIES(${Log4cpp_INCLUDE_DIR})
target_link_libraries(libevent ${Log4cpp_LIBRARY})


SET_TARGET_PROPERTIES(libevent PROPERTIES
	PREFIX ""
	OUTPUT_NAME "mod_libevent"
	SUFFIX ".so")


INSTALL(TARGETS libevent
LIBRARY DESTINATION lib/langX
)
