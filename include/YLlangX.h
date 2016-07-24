#pragma once
#include "Object.h"
#include "langX.h"

/*
*   创建时间：  2016-07-07
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     yacc/lex langX interface 文件
*              主要提供面向 yacc/lex 的一些互串 API
*/

typedef langX::Variable XVariable;
typedef langX::Node XNode;
typedef langX::ArgsList XArgsList;


//  lex/yacc 是C语言的
extern "C" {

	void initLangX();

	void closeLangX();

	double getNumberValue(const char*);

	// 创建一个字符串值得节点
	XNode * string(char *);
	// 创建一个含有数字值得 节点
	XNode * number(double );
	// 创建一个变量节点， 注意， 变量节点的名字 请使用 malloc等函数分配内存
	XNode * var(char *);
	// 创建一个 操作符节点 
	XNode * opr(int opr, int npos, ...);
	// 创建一个函数节点
	XNode * func(char *, XArgsList *,XNode *);
	// 使用一个函数
	XNode * call(char *);

	// 运算这个节点
	void execNode(XNode *);

	// 先运算，然后释放这个节点占用的内存
	void execAndFreeNode(XNode *);

	// 释放一个节点的内存
	void freeNode(XNode *);
}

langX::Object* getValue(const char*);

langX::langXState * getState();

void assignment(const char*, langX::Object * obj);