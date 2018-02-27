.PHONY: clean install

TARGET = langX

SO = mod/liblangX.so

OBJ = extern/lex.yy.o extern/y.tab.o

SRC = extern/lex.yy.c extern/y.tab.c

SO_OBJ = source/YLlangX.o source/Object.o source/Number.o source/langX.o source/ExecNode.o source/String.o source/Environment.o source/Function.o source/Allocator.o \
	source/RegFunctions.o source/ClassInfo.o source/langXObject.o source/langXObjectRef.o source/NullObject.o source/StackTrace.o source/XArray.o source/Exception.o source/XNameSpace.o \
	source/Utils.o source/X3rdModule.o source/InnerFunction.o source/Config.o source/langXThread.o source/LogManager.o

HEADER = extern/y.tab.h include/YLlangX.h include/Object.h include/Number.h include/langX.h include/ExecNode.h include/String.h include/Environment.h include/Function.h include/Allocator.h  \
	include/RegFunctions.h include/ClassInfo.h include/langXObject.h include/langXObjectRef.h include/NullObject.h include/StackTrace.h include/XArray.h include/Exception.h include/XNameSpace.h \
	include/Utils.h include/X3rdModule.h include/InnerFunction.h include/Config.h include/langXThread.h include/LogManager.h 

SO_SRC = source/YLlangX.cpp source/Object.cpp source/Number.cpp source/langX.cpp source/ExecNode.cpp source/String.cpp source/Environment.cpp source/Function.cpp \
	source/Allocator.cpp source/RegFunctions.cpp source/ClassInfo.cpp source/langXObject.cpp source/langXObjectRef.cpp source/NullObject.cpp source/StackTrace.cpp source/XArray.cpp source/Exception.cpp \
	source/XNameSpace.cpp source/Utils.cpp source/X3rdModule.cpp source/InnerFunction.cpp source/Config.cpp source/langXThread.cpp source/LogManager.cpp 


DFLAGS = -ll -ldl -L./mod -llangX -llog4cpp 

CFLAGS = -std=c++11 -g -ggdb 

SOCFLAGS = -std=c++11 -g -ggdb -fPIC

SODFLAGS = -ll -ldl -lpthread

${TARGET} : ${OBJ} ${SO}
	g++ ${CFLAGS} ${OBJ} -o ${TARGET} ${DFLAGS} 
${SO} : ${SO_OBJ}
	g++ ${SOCFLAGS} ${SO_OBJ} -shared -o ${SO} ${SODFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${SOCFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${SO_OBJ} ${SO} ${TARGET}
install:
	ln -s ~/projects/langX/mod/liblangX.so /usr/local/lib64/liblangX.so
