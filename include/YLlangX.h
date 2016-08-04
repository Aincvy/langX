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
typedef langX::ParamsList XParamsList;
typedef langX::ArgsList XArgsList;
typedef langX::Object XObject;


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
	XNode * func(char *, XParamsList *,XNode *);
	// ʹ��һ������
	XObject * call(char *, XArgsList *);
	// ����һ���ڵ㣬 �ڵ�����Ϊʵ���б�
	XNode * argsNode(XArgsList *);

	// ����һ���β��б� ���� ׷��һ�������� �б���
	XParamsList * params(XParamsList *, char *);
	// ����һ��ʵ���б� �� ����׷��һ��ʵ�ε��б���
	XArgsList * xArgs(XArgsList *, XNode *);

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