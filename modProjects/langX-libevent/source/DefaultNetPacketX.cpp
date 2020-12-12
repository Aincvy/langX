#include "../include/ReglibeventModule.h"


#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {


	Object * langX_DefaultNetPacket_DefaultNetPacket_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_DefaultNetPacket_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_DefaultNetPacket(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_DefaultNetPacket error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_setPos(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_setPos error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_getPos(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_getPos error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_getSize(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_getSize error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_writeString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_writeString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_writeDouble(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_writeDouble error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_writeInt(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_writeInt error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_readString(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_readString error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_readDouble(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_readDouble error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_DefaultNetPacket_readInt(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_DefaultNetPacket_readInt error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regDefaultNetPacket(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("DefaultNetPacket");

		info->addFunction("~DefaultNetPacket", create3rdFunc("~DefaultNetPacket", langX_DefaultNetPacket_DefaultNetPacket_Dtor));
		info->addFunction("DefaultNetPacket", create3rdFunc("DefaultNetPacket", langX_DefaultNetPacket_DefaultNetPacket));
		info->addFunction("setPos", create3rdFunc("setPos", langX_DefaultNetPacket_setPos));
		info->addFunction("getPos", create3rdFunc("getPos", langX_DefaultNetPacket_getPos));
		info->addFunction("getSize", create3rdFunc("getSize", langX_DefaultNetPacket_getSize));
		info->addFunction("writeString", create3rdFunc("writeString", langX_DefaultNetPacket_writeString));
		info->addFunction("writeDouble", create3rdFunc("writeDouble", langX_DefaultNetPacket_writeDouble));
		info->addFunction("writeInt", create3rdFunc("writeInt", langX_DefaultNetPacket_writeInt));
		info->addFunction("readString", create3rdFunc("readString", langX_DefaultNetPacket_readString));
		info->addFunction("readDouble", create3rdFunc("readDouble", langX_DefaultNetPacket_readDouble));
		info->addFunction("readInt", create3rdFunc("readInt", langX_DefaultNetPacket_readInt));

		return 0;
	}
}


