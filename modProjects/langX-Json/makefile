.PHONY: clean

TARGET = ../../mod/json.so

OBJ = source/default.o source/JsonArray.o source/JsonModule.o source/JsonObject.o 

HEADER = include/JsonModule.h include/RegJsonModule.h 

SRC = source/default.cpp source/JsonArray.cpp source/JsonModule.cpp source/JsonObject.cpp 

DFLAGS = -llangX -lcjson

CFLAGS = -std=c++11 -g -ggdb -fPIC 

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}