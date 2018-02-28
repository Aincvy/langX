
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


Object * langX_StringBuilder_append(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_StringBuilder_append error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_StringBuilder_appendLine(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_StringBuilder_appendLine error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_StringBuilder_toString(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_StringBuilder_toString error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_StringBuilder_length(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_StringBuilder_length error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


Object * langX_StringBuilder_reverse(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_StringBuilder_reverse error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}

  
  int regStringBuilder(langXState *state, XNameSpace* space) {
	
	ClassInfo *info = new ClassInfo("StringBuilder");	
info->addFunction("append", create3rdFunc("append", langX_StringBuilder_append));
info->addFunction("appendLine", create3rdFunc("appendLine", langX_StringBuilder_appendLine));
info->addFunction("toString", create3rdFunc("toString", langX_StringBuilder_toString));
info->addFunction("length", create3rdFunc("length", langX_StringBuilder_length));
info->addFunction("reverse", create3rdFunc("reverse", langX_StringBuilder_reverse));
	
	space->putClass(info);
	
  	return 0;
  }
}


