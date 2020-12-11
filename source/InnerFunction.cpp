#include "../include/InnerFunction.h"
#include "../include/Object.h"
#include "../include/ExecNode.h"
#include "../include/NodeCreator.h"
#include "../include/StringType.h"
#include "../include/Allocator.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/XArray.h"
#include "../extern/y.tab.h"
#include "../include/langXObjectRef.h"
#include "../include/langXThread.h"
#include "XNameSpace.h"
#include "ClassInfo.h"

#include <string.h>
#include <string>
#include <vector>

namespace langX {

	Object * callFunction(Object *obj, Function *func, X3rdArgs *args) {
		if (obj == nullptr || obj->getType() != OBJECT || func == nullptr)
		{
			return nullptr;
		}

		langXObjectRef *ref1 = (langXObjectRef*)obj;

		FunctionRef ref(func);
        ref.setObject(ref1->getRefObject());
		Object *retObj = ref.call(args->args, args->index, "");

		return retObj;
	}

	Object * callInnerFunc(Object *obj, Node * n) {
		// n 应该是一个函数调用节点
		if (n->type != NodeType::NODE_OPERATOR || n->opr_obj->opr != FUNC_CALL)
		{
			return Allocator::allocate(NULLOBJECT);
		}

		Node *n1 = n->opr_obj->op[0];
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		const char *remark = fileInfoString(n->fileinfo).c_str();

		char * name = n1->var_obj->name;

		// 转换参数   , 外部传来的时候参数的值都是存在的，直接使用就好了
		X3rdArgs _3rdArgs;
		memset(&_3rdArgs, 0, sizeof(X3rdArgs));
		if (args)
		{
			for (int i = 0; i < args->index; i++)
			{
				if (args->args[i] == NULL)
				{
					_3rdArgs.args[i] = NULL;
					continue;
				}

				Object *obj = args->args[i]->value;
				if (obj)
				{
					_3rdArgs.args[i] = obj->clone();
				}
				else {
					_3rdArgs.args[i] = Allocator::allocate(NULLOBJECT);
				}

				// 释放这个参数节点的值
				Allocator::free(args->args[i]->value);
				args->args[i]->value = NULL;
			}
			_3rdArgs.index = args->index;
		}

		Object *ret = callInnerFunc(obj, name, &_3rdArgs);

		for (size_t i = 0; i < _3rdArgs.index; i++)
		{
			Allocator::free(_3rdArgs.args[i]);
		}

		return ret;
	}

	Object * callInnerFunc(Object *obj, const char *name, X3rdArgs *args)
	{
		Object *ret = nullptr;

		if (obj->getType() == STRING)
		{
		    auto stringClass = getState()->getNameSpace("langX.extend")->getClass("String");
			auto func = stringClass->getFunction(name);
            if (func != nullptr) {
                // 存在该函数， 把字符串当成参数丢进去
                FunctionRef ref(func);
                ref.setObject(nullptr);

                Object* realArgs[1 + args->index];
                realArgs[0] = obj;
                for (int i = 0; i < args->index; ++i) {
                    realArgs[i + 1] = args->args[i];
                }
                ret = ref.call(realArgs, 1, "call from inner func");
            }

		}

		if (ret == nullptr)
		{
			ret = Allocator::allocate(NULLOBJECT);
		}
		return ret;
	}
}
