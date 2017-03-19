#include <stack>

#include "../include/RegCoreModule.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"

namespace langX {

	Object * langX_Stack_Stack(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Queue error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = new std::stack<Object*>();
		args.object->set3rdObj(stack);

		return nullptr;
	}

	Object * langX_Stack_Stack_Dtor(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Queue_Dtor error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = (std::stack<Object*> *)args.object->get3rdObj();

		for (int i = 0; i < stack->size(); i++)
		{
			Object *t = stack->top();
			stack->pop();
			Allocator::free(t);
		}

		delete stack;

		return nullptr;
	}

	Object * langX_Stack_Top(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = (std::stack<Object*> *)args.object->get3rdObj();
		if (stack->empty())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		return Allocator::copy(stack->top());
	}

	Object * langX_Stack_Pop(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = (std::stack<Object*> *)args.object->get3rdObj();
		if (stack->empty())
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Object *obj = stack->top();
		stack->pop();

		// obj 已经从 queue中移除， 释放obj 的操作其他地方会做
		return obj;
	}

	Object * langX_Stack_Push(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = (std::stack<Object*> *)args.object->get3rdObj();
		Object *a = args.args[0];
		if (a != nullptr)
		{
			stack->push(a->clone());
		}

		return nullptr;
	}

	Object * langX_Stack_Size(X3rdFunction *func, const X3rdArgs &args) {
		if (args.object == nullptr)
		{
			printf("langX_Queue_Top error! NO OBJ!\n");
			return nullptr;
		}

		std::stack<Object*> * stack = (std::stack<Object*> *)args.object->get3rdObj();

		return Allocator::allocateNumber(stack->size());
	}

	int regStack(langXState *state, XNameSpace* space) {
		ClassInfo *stack = new ClassInfo("Stack");
		stack->addFunction("Stack", create3rdFunc("Stack", langX_Stack_Stack));
		stack->addFunction("~Stack", create3rdFunc("~Stack", langX_Stack_Stack_Dtor));
		stack->addFunction("top", create3rdFunc("top", langX_Stack_Top));
		stack->addFunction("pop", create3rdFunc("pop", langX_Stack_Pop));
		stack->addFunction("push", create3rdFunc("push", langX_Stack_Push));
		stack->addFunction("size", create3rdFunc("size", langX_Stack_Size));
		space->putClass(stack);
		return 0;
	}

}