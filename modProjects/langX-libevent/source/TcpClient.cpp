#include "../include/ReglibeventModule.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_TcpClient_TcpClient_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpClient_TcpClient_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		TcpClientArgs *clientArgs = (TcpClientArgs*)args.object->get3rdObj();
		if (clientArgs != nullptr)
		{
			free(clientArgs);
			args.object->set3rdObj(nullptr);
		}

		return nullptr;
	}



	Object * langX_TcpClient_TcpClient(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpClient_TcpClient error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}

	Object * langX_TcpClient_write(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpClient_write error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	Object * langX_TcpClient_close(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_TcpClient_close error! NO OBJ!\n");
			return nullptr;
		}

		return nullptr;
	}



	int regTcpClient(langXState *state, XNameSpace* space) {

		ClassInfo *info = new ClassInfo("TcpClient");
		info->addMember("isConnected", getState()->getAllocator().allocateNumber(0));
		info->addMember("available", getState()->getAllocator().allocateNumber(0));

		info->addFunction("write", create3rdFunc("write", langX_TcpClient_write));
		info->addFunction("close", create3rdFunc("close", langX_TcpClient_close));
		info->addFunction("~TcpClient", create3rdFunc("~TcpClient", langX_TcpClient_TcpClient_Dtor));
		info->addFunction("TcpClient", create3rdFunc("TcpClient", langX_TcpClient_TcpClient));
		space->putClass(info);

		return 0;
	}
}