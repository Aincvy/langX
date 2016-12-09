
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


Object * langX_FileStream_close(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_close error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_eof(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_eof error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_length(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_length error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_writeLine(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_writeLine error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_writeByte(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_writeByte error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_write(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_write error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_readLine(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_readLine error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_read(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_read error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_FileStream_Dtor(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_FileStream_Dtor error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}



Object * langX_FileStream_FileStream(X3rdFunction *func, const X3rdArgs &args) {
	if (args.object == nullptr)
	{
		printf("langX_FileStream_FileStream error! NO OBJ!\n");
		return nullptr;
	}

	return nullptr;
}


  
  int regFileStream(langXState *state, XNameSpace* space) {
	
	ClassInfo *info = new ClassInfo("FileStream");	
info->addFunction("close", create3rdFunc("close", langX_FileStream_close));

info->addFunction("eof", create3rdFunc("eof", langX_FileStream_eof));

info->addFunction("length", create3rdFunc("length", langX_FileStream_length));

info->addFunction("writeLine", create3rdFunc("writeLine", langX_FileStream_writeLine));

info->addFunction("writeByte", create3rdFunc("writeByte", langX_FileStream_writeByte));

info->addFunction("write", create3rdFunc("write", langX_FileStream_write));

info->addFunction("readLine", create3rdFunc("readLine", langX_FileStream_readLine));

info->addFunction("read", create3rdFunc("read", langX_FileStream_read));

info->addFunction("~FileStream", create3rdFunc("~FileStream", langX_FileStream_FileStream_Dtor));

info->addFunction("FileStream", create3rdFunc("FileStream", langX_FileStream_FileStream));

	
	space->putClass(info);
	
  	return 0;
  }
}


