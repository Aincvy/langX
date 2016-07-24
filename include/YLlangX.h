#pragma once
#include "Object.h"
#include "langX.h"

/*
*   ����ʱ�䣺  2016-07-07
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     yacc/lex langX interface �ļ�
*              ��Ҫ�ṩ���� yacc/lex ��һЩ���� API
*/

typedef langX::Variable XVariable;
typedef langX::Node XNode;
typedef langX::ArgsList XArgsList;


//  lex/yacc ��C���Ե�
extern "C" {

	void initLangX();

	void closeLangX();

	double getNumberValue(const char*);

	// ����һ���ַ���ֵ�ýڵ�
	XNode * string(char *);
	// ����һ����������ֵ�� �ڵ�
	XNode * number(double );
	// ����һ�������ڵ㣬 ע�⣬ �����ڵ������ ��ʹ�� malloc�Ⱥ��������ڴ�
	XNode * var(char *);
	// ����һ�� �������ڵ� 
	XNode * opr(int opr, int npos, ...);
	// ����һ�������ڵ�
	XNode * func(char *, XArgsList *,XNode *);
	// ʹ��һ������
	XNode * call(char *);

	// ��������ڵ�
	void execNode(XNode *);

	// �����㣬Ȼ���ͷ�����ڵ�ռ�õ��ڴ�
	void execAndFreeNode(XNode *);

	// �ͷ�һ���ڵ���ڴ�
	void freeNode(XNode *);
}

langX::Object* getValue(const char*);

langX::langXState * getState();

void assignment(const char*, langX::Object * obj);