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
typedef langX::NodeLink NodeLink;


//  lex/yacc 是C语言的
extern "C" {

	void initLangX(int argc,char *argv[]);

	void closeLangX();

	double getNumberValue(const char*);

	// 创建一个字符串值得节点
	XNode * string(char *);
	// 创建一个含有数字值得 节点
	XNode * number(double );
	// 创建一个变量节点， 注意， 变量节点的名字 请使用 malloc等函数分配内存
	XNode * var(char *);
	// 创建一个 操作符节点
	XNode * opr(int opr, int size, ...);
	// 创建一个后缀节点
	XNode * sopr(int opr, int npos, ...);
	// 创建一个 空引用节点
	XNode * xnull();
// 创建一个节点， 节点内容为实参列表
	XNode * argsNode(XArgsList *);
	// 创建一个数组元素节点
	XNode *arrayElementNode(char *, XNode *);
	// 创建一个数组元素节点
	XNode *objectArrayElementNode(XNode *, XNode *);
	// 创建一个int类型的常量节点
	XNode *intNode(int);
	// 预处理 switch 节点
	void pretreatSwitch(XNode *);

	// 释放参数列表的 内存
	void freeArgsList(XArgsList *);

	// 运算这个节点
	void execNode(XNode *);
	// 运算这个节点，但是会截止到某个执行链路
	void execNodeButLimit(XNode *n, XNode *limit);

	// 先运算，然后释放这个节点占用的内存
	void execAndFreeNode(XNode *);

	// 释放一个节点的内存
	void freeNode(XNode *);

	void popStateFrame();

	// 真正处理文件结束的工作
	void fileEOF();

	const char* getParsingFilename();

	// 执行文件
	void doFile(const char *);

	// yy 解析停止了 
	void yyParseStopped();

	// lex 碰到一个文件结束符
    void endOfFileFlag();
}

langX::Object* getValue(const char*);

langX::langXState * getState();

// 把文件信息变一下
std::string fileInfoString(const langX::NodeFileInfo & f);

// 创建一个第三方函数
XFunction* create3rdFunc(const char *, langX::X3rdFuncWorker);

// 将一个 langXObject 转成字符串， 可能会调用该对象的 toString() 方法
void objToString(langX::Object * obj,char *, int offset, int maxSize);

//  获取一个对象的字符串描述
void getObjStringDesc(langX::Object *obj, char *, int maxSize);
