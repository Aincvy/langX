.PHONY: clean

TARGET = ../../mod/core.so

OBJ = source/CoreModule.o source/Default.o source/Iterator.o source/List.o source/Map.o source/Queue.o source/Set.o source/Stack.o source/Math.o source/Vector.o

HEADER = include/CoreModule.h include/RegCoreModule.h 

SRC = source/CoreModule.cpp source/Default.cpp source/Iterator.cpp source/List.cpp source/Map.cpp source/Queue.cpp source/Set.cpp source/Stack.cpp source/Math.cpp source/Vector.cpp

DFLAGS = -llangX

CFLAGS = -std=c++11 -g -ggdb -fPIC

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}