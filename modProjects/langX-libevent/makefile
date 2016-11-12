.PHONY: clean

TARGET = ../../mod/mod_libevent.so

OBJ = source/BytesDecoder.o source/BytesEncoder.o source/DefaultBytesDecoder.o source/DefaultBytesEncoder.o source/DefaultNetPacket.o source/DefaultNetPacketX.o \
	source/libeventModule.o source/TcpClient.o source/TcpServer.o 

HEADER = include/BytesDecoder.h include/BytesEncoder.h include/DefaultBytesDecoder.h include/DefaultBytesEncoder.h include/DefaultNetPacket.h include/libeventModule include/ReglibeventModule

SRC = source/BytesDecoder.cpp source/BytesEncoder.cpp source/DefaultBytesDecoder.cpp source/DefaultBytesEncoder.cpp source/DefaultNetPacket.cpp \
	source/DefaultNetPacketX.cpp source/libeventModule.cpp source/TcpClient.cpp source/TcpServer.cpp 

DFLAGS = -llangX -levent

CFLAGS = -std=c++11 -g -ggdb -fPIC

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}