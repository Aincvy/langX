.PHONY: clean

TARGET = langX

OBJ = extern/lex.yy.o extern/y.tab.o source/YLlangX.o source/Object.o source/Number.o source/langX.o source/ExecNode.o source/String.o source/Environment.o 

HEADER = extern/y.tab.h include/YLlangX.h include/Object.h include/Number.h include/langX.h include/ExecNode.h include/String.h include/Environment.h 

SRC = extern/lex.yy.c extern/y.tab.c source/YLlangX.cpp source/Object.cpp source/Number.cpp source/langX.cpp source/ExecNode.cpp source/String.cpp source/Environment.cpp 

DFLAGS = -ll

CFLAGS = -std=c++11 -g -ggdb 


${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< ${DFLAGS}
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}