#include <queue>

#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/NodeCreator.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_Queue_Queue(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Queue error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = new std::queue<Object*>();
		args.object->set3rdObj(queue);

		return nullptr;
	}

	Object * langX_Queue_Queue_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Queue_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = (std::queue<Object*> *)args.object->get3rdObj();

		for (int i = 0; i < queue->size(); i++)
		{
			Object *t = queue->front();
			queue->pop();
			Allocator::free(t);
		}

		delete queue;

		return nullptr;
	}

	Object * langX_Queue_Top(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = (std::queue<Object*> *)args.object->get3rdObj();
		if (queue->empty())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		return Allocator::copy(queue->front());
	}

	Object * langX_Queue_Pop(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = (std::queue<Object*> *)args.object->get3rdObj();
		if (queue->empty())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Object *obj = queue->front();
		queue->pop();

		// obj 已经从 queue中移除， 释放obj 的操作其他地方会做
		return obj;
	}

	Object * langX_Queue_Push(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = (std::queue<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			queue->push(a->clone());
		}

		return nullptr;
	}

	Object * langX_Queue_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::queue<Object*> * queue = (std::queue<Object*> *)args.object->get3rdObj();

		return Allocator::allocateNumber(queue->size());
	}


	int regQueue(langXState *state, XNameSpace* space) {

		ClassInfo *queue = new ClassInfo("Queue");
		queue->addFunction("Queue", create3rdFunc("Queue", langX_Queue_Queue));
		queue->addFunction("~Queue", create3rdFunc("~Queue", langX_Queue_Queue_Dtor));
		queue->addFunction("top", create3rdFunc("top", langX_Queue_Top));
		queue->addFunction("pop", create3rdFunc("pop", langX_Queue_Pop));
		queue->addFunction("push", create3rdFunc("push", langX_Queue_Push));
		queue->addFunction("size", create3rdFunc("size", langX_Queue_Size));
		space->putClass(queue);

		return 0;
	}

}