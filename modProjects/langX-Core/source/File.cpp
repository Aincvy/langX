
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


Object * langX_File_appendLines(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_appendLines error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_appendText(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_appendText error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_readLines(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_readLines error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_readText(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_readText error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_writeLines(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_writeLines error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_writeText(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_writeText error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_openAppend(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_openAppend error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_openWrite(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_openWrite error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_File_openRead(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_File_openRead error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


  
  int regFile(langXState *state, XNameSpace* space) {
	
	ClassInfo *info = new ClassInfo("File");	
info->addFunction("appendLines", create3rdFunc("appendLines", langX_File_appendLines));

info->addFunction("appendText", create3rdFunc("appendText", langX_File_appendText));

info->addFunction("readLines", create3rdFunc("readLines", langX_File_readLines));

info->addFunction("readText", create3rdFunc("readText", langX_File_readText));

info->addFunction("writeLines", create3rdFunc("writeLines", langX_File_writeLines));

info->addFunction("writeText", create3rdFunc("writeText", langX_File_writeText));

info->addFunction("openAppend", create3rdFunc("openAppend", langX_File_openAppend));

info->addFunction("openWrite", create3rdFunc("openWrite", langX_File_openWrite));

info->addFunction("openRead", create3rdFunc("openRead", langX_File_openRead));

	
	space->putClass(info);
	
  	return 0;
  }
}


