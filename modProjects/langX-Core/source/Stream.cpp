#include "RegCoreModule.h"

#include "langXSimple.h"


namespace langX {


	Object * langX_Stream_Stream_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_Stream_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_Stream(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_Stream error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_length(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_length error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_close error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_eof(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_eof error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_writeByte(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_writeByte error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_write(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_write error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_Stream_read(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Stream_read error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	ClassInfo* regStream(langXState *state, XNameSpace* space){

		ClassInfo *info = new ClassInfo("Stream");
		info->addFunction("~Stream", create3rdFunc("~Stream", langX_Stream_Stream_Dtor));
		info->addFunction("Stream", create3rdFunc("Stream", langX_Stream_Stream));
		info->addFunction("length", create3rdFunc("length", langX_Stream_length));
		info->addFunction("close", create3rdFunc("close", langX_Stream_close));
		info->addFunction("eof", create3rdFunc("eof", langX_Stream_eof));
		info->addFunction("writeByte", create3rdFunc("writeByte", langX_Stream_writeByte));
		info->addFunction("write", create3rdFunc("write", langX_Stream_write));
		info->addFunction("read", create3rdFunc("read", langX_Stream_read));

		space->putClass(info);

		return info;
	}
}


