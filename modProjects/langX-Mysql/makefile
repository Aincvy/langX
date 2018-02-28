.PHONY: clean

MYSQL_H_F = /usr/include/mysql
MYSQL_L_F = /usr/lib64/mysql

TARGET = ../../mod/mysql.so

OBJ = source/MysqlModule.o source/DataRow.o source/DataTable.o source/MysqlClient.o

HEADER = include/MysqlModule.h include/RegMysqlModule.h 

SRC = source/MysqlModule.cpp source/DataRow.cpp source/DataTable.cpp source/MysqlClient.cpp

DFLAGS = -llangX -L ${MYSQL_L_F} -lmysqlclient

CFLAGS = -std=c++11 -g -ggdb -fPIC -I ${MYSQL_H_F}

${TARGET} : ${OBJ}
	g++ ${CFLAGS} ${OBJ} -shared -o ${TARGET} ${DFLAGS}
.cpp.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
.c.o: ${HEADER} ${SRC}
	g++ ${CFLAGS} -c -o $@ $< 
clean:
	rm -f ${OBJ} ${TARGET}
