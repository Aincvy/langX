#include <stdio.h>

#include "../include/RegFunctions.h"
#include "../include/Function.h"
#include "../include/Object.h"
#include "../include/String.h"
#include "../include/Number.h"

namespace langX {

	// c printf 函数 的桥接
	Object * langX_print(X3rdFunction *func,const X3rdArgs & args) {
		if (args.index <= 0)
		{
			printf("function %s need at least 1 param!\n" , func->getName() );
			return NULL;
		}

		// 先试试单参数
		Object *obj = args.args[0];
		if (obj == NULL)
		{
			printf("function %s error param!\n" , func->getName() );
			return NULL;
		}
		if (obj->getType() == STRING)
		{
			String * str = (String*)obj;
			str->simpleEscape();
			printf(str->getValue() );
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

	// 读取出一个字符串
	Object * langX_scan_string(X3rdFunction *func, const X3rdArgs & args) {

		char t[100] = { 0 };
		scanf("%s", t);

		return new String(t);
	}

	// 读取一个数字
	Object * langX_scan_number(X3rdFunction *func, const X3rdArgs & args) {

		double a;
		scanf("%lf",&a);

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
		state->reg3rd("scanNumber",langX_scan_number);
		state->reg3rd("printStackTrace", langX_print_stack_trace);
	}

}