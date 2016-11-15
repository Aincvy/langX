#include "../include/InnerFunction.h"
#include "../include/Object.h"
#include "../include/ExecNode.h"
#include "../include/YLlangX.h"
#include "../include/String.h"
#include "../include/Allocator.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/XArray.h"
#include "../extern/y.tab.h"

#include <string.h>
#include <string>
#include <vector>


namespace langX {


	Object * callInnerFunc(Object *obj, Node * n) {
		// n 应该是一个函数调用节点
		if (n->type != NodeType::NODE_OPERATOR || n->opr_obj->opr != FUNC_CALL)
		{
			return getState()->getAllocator().allocate(NULLOBJECT);
		}

		Node *n1 = n->opr_obj->op[0];
		XArgsList *args = (XArgsList *)n->opr_obj->op[1]->ptr_u;
		const char *remark = fileInfoString(n->fileinfo).c_str();

		char * name = n1->var_obj->name;

		// 转换参数
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

				// 释放这个参数节点的值先

				getState()->getAllocator().free(args->args[i]->value);
				args->args[i]->value = NULL;
				//freeSubNodes(args->args[i]);

				execNode(args->args[i]);

				if (getState()->getCurrentEnv()->isDead())
				{
					return NULL;
				}

				_3rdArgs.args[i] = args->args[i]->value;
			}
			_3rdArgs.index = args->index;
		}

		Object *ret = callInnerFunc(obj, name, &_3rdArgs);

		if (!n->state.in_func && !n->state.in_loop)
		{
			freeArgsList(args);
		}

		return ret;
	}

	Object * callInnerFunc(Object *obj, const char *name, X3rdArgs *args)
	{

		Object *ret = nullptr;

		if (obj->getType() == STRING)
		{
			String * str = (String* )obj;
			
			if (strcmp(name,"length") == 0)
			{
				ret = getState()->getAllocator().allocateNumber(str->size());
			}
			else if (strcmp(name, "subString") == 0)
			{
				int index = -1, len = -1;
				Object *a = args->args[0];
				if (a && a->getType() == NUMBER)
				{
					index = ((Number*)a)->getIntValue();
				}

				a = args->args[1];
				if (a && a->getType() == NUMBER)
				{
					len = ((Number*)a)->getIntValue();
				}

				if (index == -1)
				{
					return getState()->getAllocator().allocate(NULLOBJECT);
				}

				if (len == -1)
				{
					return getState()->getAllocator().allocateString(str->subStr(index).c_str());
				}

				return getState()->getAllocator().allocateString(str->subStr(index,len).c_str());
			}
			else if (strcmp(name, "contains") == 0)
			{
				Object *a = args->args[0];
				if (a && a->getType() == STRING)
				{
					if ( str->contains(((String*)a)->getValue()) )
					{
						return getState()->getAllocator().allocateNumber(1);
					}
				}

				return getState()->getAllocator().allocateNumber(0);
			}
			else if (strcmp(name, "indexOf") == 0)
			{
				Object *a = args->args[0];
				if (a && a->getType() == STRING)
				{
					int i = str->indexOf(((String*)a)->getValue());

					return getState()->getAllocator().allocateNumber(i);
					
				}

				return getState()->getAllocator().allocateNumber(-1);
			}
			else if (strcmp(name, "isEmpty") == 0)
			{
				if (str->isEmpty())
				{
					return getState()->getAllocator().allocateNumber(1);
				}

				return getState()->getAllocator().allocateNumber(0);
			}
			else if (strcmp(name, "replace") == 0)
			{
				Object *a = args->args[0];
				Object *b = args->args[1];

				if (a && b && a->getType() == STRING && b->getType() == STRING)
				{
					String *str1 = (String*)a;
					String *str2 = (String*)b;
					std::string t1 = str->replace(str1->getValue(), str2->getValue());
					return getState()->getAllocator().allocateString(t1.c_str());
				}
				return getState()->getAllocator().allocate(NULLOBJECT);
			}
			else if (strcmp(name, "replaceFirst") == 0)
			{
				Object *a = args->args[0];
				Object *b = args->args[1];

				if (a && b && a->getType() == STRING && b->getType() == STRING)
				{
					String *str1 = (String*)a;
					String *str2 = (String*)b;
					std::string t1 = str->replaceFirst(str1->getValue(), str2->getValue());
					return getState()->getAllocator().allocateString(t1.c_str());
				}
				return getState()->getAllocator().allocate(NULLOBJECT);
			}
			else if (strcmp(name, "split") == 0)
			{
				Object *a = args->args[0];
				if (a && a->getType() == STRING)
				{
					std::vector<std::string> vector1 = str->split(((String*)a)->getValue());

					XArray *array1 = getState()->getAllocator().allocateArray(vector1.size());
					int index = 0;
					for (auto i = vector1.begin(); i != vector1.end(); i++)
					{
						array1->set(index++, getState()->getAllocator().allocateString(((*i).c_str())));
					}

					return array1->addRef();
				}
				return getState()->getAllocator().allocate(NULLOBJECT);
			}
			else if (strcmp(name, "lowerCase") == 0)
			{
				std::string t1 = str->lowerCase();
				return getState()->getAllocator().allocateString(t1.c_str());
			}
			else if (strcmp(name, "upperCase") == 0)
			{
				std::string t1 = str->upperCase();
				return getState()->getAllocator().allocateString(t1.c_str());
			}

		}

		if (ret == nullptr)
		{
			ret = getState()->getAllocator().allocate(NULLOBJECT);
		}
		return ret;
	}


}