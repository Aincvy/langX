.PHONY: clean

TARGET = langX

OBJ = extern/lex.yy.o extern/y.tab.o source/YLlangX.o source/Object.o source/Number.o source/langX.o source/ExecNode.o source/String.o source/Environment.o source/Function.o source/Allocator.o \
	source/RegFunctions.o source/ClassInfo.o source/langXObject.o source/langXObjectRef.o source/NullObject.o source/StackTrace.o source/XArray.o source/Exception.o source/XNameSpace.o \
	source/DestroyedObject.o source/Utils.o source/X3rdModule.o

HEADER = extern/y.tab.h include/YLlangX.h include/Object.h include/Number.h include/langX.h include/ExecNode.h include/String.h include/Environment.h include/Function.h include/Allocator.h  \
	include/RegFunctions.h include/ClassInfo.h include/langXObject.h include/langXObjectRef.h include/NullObject.h include/StackTrace.h include/XArray.h include/Exception.h include/XNameSpace.h \
	include/DestroyedObject.h include/Utils.h include/X3rdModule.h

SRC = extern/lex.yy.c extern/y.tab.c source/YLlangX.cpp source/Object.cpp source/Number.cpp source/langX.cpp source/ExecNode.cpp source/String.cpp source/Environment.cpp source/Function.cpp \
	source/Allocator.cpp source/RegFunctions.cpp source/ClassInfo.cpp source/langXObject.cpp source/langXObjectRef.cpp source/NullObject.cpp source/StackTrace.cpp source/XArray.cpp source/Exception.cpp \
	source/XNameSpace.cpp source/DestroyedObject.cpp source/Utils.cpp source/X3rdModule.cpp


DFLAGS = -ll -ldl

CFLAGS = -std=c++11 -g -ggdb 


${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< ${DFLAGS}
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}