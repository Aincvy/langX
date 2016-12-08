#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <string.h>

#include "../include/RegFunctions.h"
#include "../include/Function.h"
#include "../include/Object.h"
#include "../include/String.h"
#include "../include/Number.h"
#include "../include/YLlangX.h"

namespace langX {

	// c printf 函数 的桥接
	Object * langX_print(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
		}

		// 先试试单参数
		Object *obj = args.args[0];
		if (obj == NULL)
		{
			printf("function %s error param!\n", func->getName());
			return NULL;
		}
		if (obj->getType() == STRING)
		{
			String * str = (String*)obj;
			str->simpleEscape();

			if (args.index == 1)
			{
				printf(str->getValue());
			}
			else {
				char tmp[2048] = { 0 };
				int pos = 0;
				for (size_t i = 1; i < args.index; i++)
				{
					Object *tobj = args.args[i];
					if (tobj == NULL || tobj->getType() == NULLOBJECT)
					{
						const char * tp = "null\0";
						int size = strlen(tp);
						memcpy(tmp + pos, tp, size);
						pos += size;
						continue;
					}
					else if (tobj->getType() == NUMBER)
					{
						Number * num = (Number*)tobj;
						if (num->isInteger())
						{
							int v = num->getIntValue();
							memcpy(tmp + pos, &v, sizeof(int));
							pos += sizeof(int);
							continue;
						}
						else {
							double v = num->getDoubleValue();
							memcpy(tmp + pos, &v, sizeof(double));
							pos += sizeof(double);
							continue;
						}
					}
					else if (tobj->getType() == STRING)
					{
						const char * tp = ((String*)tobj)->getValue();
						int size = strlen(tp);
						memcpy(tmp + pos, tp, size);
						pos += size;
						continue;
					}
					else if (tobj->getType() == OBJECT)
					{
						char atmp[2048] = { 0 };
						objToString(tobj, atmp, 0, 2048);
						int size = strlen(atmp);
						memcpy(tmp + pos, atmp, size);
						pos += size;
					}
				}

				
				va_list vas = tmp;
				vprintf(str->getValue(), vas);
			}
		}
		else if (obj->getType() == NUMBER)
		{
			printf("%f", ((Number*)obj)->getDoubleValue());
		}
		else if (obj->getType() == NULLOBJECT)
		{
			printf("null");
		}
		else if (obj->getType() == OBJECT)
		{
			printf("object");
		}

		return NULL;
	}

	//  c system 函数的桥接
	Object * langX_system_run(X3rdFunction *func, const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n", func->getName());
			return NULL;
		}

		// 先试试单参数
		Object *obj = args.args[0];
		if (obj == NULL)
		{
			printf("function %s error param!\n", func->getName());
			return NULL;
		}
		if (obj->getType() == STRING)
		{
			String * str = (String*)obj;
			str->simpleEscape();
			system(str->getValue());
		}

		return NULL;
	}


	// 读取出一个字符串
	Object * langX_scan_string(X3rdFunction *func, const X3rdArgs & args) {

		char t[100] = { 0 };
		scanf("%s", t);

		return new String(t);
	}

	// 读取一个数字
	Object * langX_scan_number(X3rdFunction *func, const X3rdArgs & args) {

		double a;
		scanf("%lf", &a);

		return new Number(a);
	}

	Object * langX_print_stack_trace(X3rdFunction *func, const X3rdArgs & args) {

		func->getLangX()->printStackTrace();

		return NULL;
	}

	void regFunctions(langXState *state)
	{
		state->reg3rd("print", langX_print);
		state->reg3rd("scanString", langX_scan_string);
		state->reg3rd("scanNumber", langX_scan_number);
		state->reg3rd("printStackTrace", langX_print_stack_trace);
		state->reg3rd("systemRun", langX_system_run);
	}

}