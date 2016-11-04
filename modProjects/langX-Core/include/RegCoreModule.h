#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	// ע�� Iterator ��
	int regIterator(langXState *state , XNameSpace* space);
	
	// ע�� List ��
	int regList(langXState *state, XNameSpace* space);

	// ע�� Map ��
	int regMap(langXState *state, XNameSpace* space);

	// ע�� Set��
	int regSet(langXState *state, XNameSpace* space);

	// 
	int regQueue(langXState *state, XNameSpace* space);

	// 
	int regStack(langXState *state, XNameSpace* space);

	//
	int regVector(langXState *state, XNameSpace* space);

	//  core ��Ķ��� �����涼��core.util ����Ķ���
	int regDeafult(langXState *state, XNameSpace* space);
}
