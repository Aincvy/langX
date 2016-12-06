.PHONY: clean

TARGET = ../../mod/python3_x.so

OBJ = source/PythonHook.o source/PythonLib.o source/PythonModule.o source/PyException.o source/PyObject.o source/PyObjectType.o

HEADER = include/PythonModule.h include/RegPythonModule.h 

SRC = source/PythonHook.cpp source/PythonLib.cpp source/PythonModule.cpp source/PyException.cpp source/PyObject.cpp source/PyObjectType.cpp

DFLAGS = -llangX -lpython3

CFLAGS = -std=c++11 -g -ggdb -fPIC 

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}