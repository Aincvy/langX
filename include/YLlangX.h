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
	XNode * claxx(char *name, char *parent, XNode * node , bool);
	// 创建一个函数节点
	XNode * func(char *, XParamsList *,XNode *);
	// 创建一个析构函数节点
	XNode * dtrt(char *, XParamsList *, XNode *);
	// 创建一个数组节点， 在执行这个节点的时候会创建一个数组
	XNode * arrayNode(char *,int length, XNode *);
	// 创建一个 空引用节点
	XNode * xnull();
	// 使用一个函数
	XObject * call(const char *, XArgsList *, const char *, NodeLink *);
	// 调用一个函数
	XObject * callFunc(XFunction*, XArgsList *, const char *, NodeLink*);
	// 创建一个节点， 节点内容为实参列表
	XNode * argsNode(XArgsList *);
	// 创建一个数组元素节点
	XNode *arr(char *, int ,XNode *);
	// 创建一个数组元素节点
	XNode *arr2(XNode *, int, XNode *);
	// 创建一个int类型的常量节点
	XNode *xint(int);
	// 切换命名空间
	XNode *changeNameSpace(char *);
	// 生成一个lamdba 表达式的节点
	XNode *lambda(XParamsList *,XNode *);
	// 创建一个形参列表， 或者 追加一个参数到 列表中
	XParamsList * params(XParamsList *, char *);
	// xx
	XParamsList * params2(char *,char *);
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

	void popStateFrame();

	// 当lex 碰到文件结束符的时候应该调用这个方法
	void fileEOF();

	const char* getParsingFilename();

	// 执行文件
	void doFile(const char *);
}

langX::Object* getValue(const char*);

langX::langXState * getState();

void assignment(const char*, langX::Object * obj);

// 把文件信息变一下
std::string fileInfoString(const langX::NodeFileInfo & f);

// 创建一个第三方函数
XFunction* create3rdFunc(const char *, langX::X3rdFuncWorker);

void objToString(langX::Object * obj,char *, int offset, int maxSize);



