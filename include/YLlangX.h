#pragma once
#include "Object.h"
#include "langX.h"
#include "Function.h"
#include <string>

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
typedef langX::ParamsList XParamsList;
typedef langX::ArgsList XArgsList;
typedef langX::Object XObject;
typedef langX::Function XFunction;


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
	// 创建一个后缀节点
	XNode * sopr(int opr, int npos, ...);
	// 创建一个类节点
	XNode * claxx(char *name, char *parent, XNode * node);
	// 创建一个函数节点
	XNode * func(char *, XParamsList *,XNode *);
	// 创建一个 空引用节点
	XNode * xnull();
	// 使用一个函数
	XObject * call(char *, XArgsList *, const char *);
	// 调用一个函数
	XObject * callFunc(XFunction*, XArgsList *, const char *);
	// 创建一个节点， 节点内容为实参列表
	XNode * argsNode(XArgsList *);

	// 创建一个形参列表， 或者 追加一个参数到 列表中
	XParamsList * params(XParamsList *, char *);
	// 创建一个实参列表 ， 或者追加一个实参到列表中
	XArgsList * xArgs(XArgsList *, XNode *);

	// 释放参数列表的 内存
	void freeArgsList(XArgsList *);

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

// 把文件信息变一下
std::string fileInfoString(const langX::NodeFileInfo & f);