#pragma once

// �ڲ�����  InnerFunction.h ,  

#include "Object.h"

namespace langX {

	// ��һ������Ϊ ���� �ڶ�������Ϊ �������õĽڵ�
	Object * callInnerFunc(Object *, Node *);
	
	// ��һ������Ϊ ���� �ڶ�������Ϊ �������֣� ������Ϊ��������
	Object * callInnerFunc(Object *, const char *, X3rdArgs *);
}