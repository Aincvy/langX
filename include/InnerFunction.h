#pragma once

// �ڲ�����  InnerFunction.h ,  

#include "Object.h"
#include "Function.h"

namespace langX {

	// ��һ������Ϊ ���� �ڶ�������Ϊ �������õĽڵ�
	Object * callInnerFunc(Object *, Node *);
	
	// ��һ������Ϊ ���� �ڶ�������Ϊ �������֣� ������Ϊ��������
	Object * callInnerFunc(Object *, const char *, X3rdArgs *);

	// ��һ������Ϊʹ�ú����Ķ��� �ڶ�������Ϊ������ ����������Ϊ �����б�
	Object * callFunction(Object *, Function *, X3rdArgs *);
}