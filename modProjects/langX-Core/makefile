.PHONY: clean

TARGET = ../../mod/core.so

OBJ = source/CoreModule.o ../../source/X3rdModule.o

HEADER = include/CoreModule.h ../../include/X3rdModule.h

SRC = source/CoreModule.cpp ../../source/X3rdModule.cpp

DFLAGS = 

CFLAGS = -std=c++11 -g -ggdb -fPIC

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< ${DFLAGS}
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}