#pragma once
#include "langX.h"

/*
 * ע��һЩ���� ����Ŀռ�����
 */

namespace langX {

	class langXObjectExtend;

	// ע��
	void regObjects(langXState *state);

	// ����һ���յĶ���
	langXObjectExtend *emptyObject();

}