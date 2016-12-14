#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

namespace langX {

	class ClassInfo;

	// 注册 Iterator 类
	int regIterator(langXState *state , XNameSpace* space);
	
	// 注册 List 类
	int regList(langXState *state, XNameSpace* space);

	// 注册 Map 类
	int regMap(langXState *state, XNameSpace* space);

	// 注册 Set类
	int regSet(langXState *state, XNameSpace* space);

	// 
	int regQueue(langXState *state, XNameSpace* space);

	// 
	int regStack(langXState *state, XNameSpace* space);

	//
	int regVector(langXState *state, XNameSpace* space);

	//  core 库的东西 ，上面都是core.util 里面的东西
	int regDeafult(langXState *state, XNameSpace* space);


	// io 库里面的
	int regFile(langXState *state, XNameSpace* space);

	int regByteArray(langXState *state, XNameSpace* space);

	ClassInfo* regStream(langXState *state, XNameSpace* space);

	int regFileStream(langXState *state, XNameSpace* space, ClassInfo *stream);

}
