#include <stdio.h>

#include "../include/RegFunctions.h"
#include "../include/Function.h"
#include "../include/Object.h"

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
			printf(((String*)obj)->getValue());
			printf("\n");
		}
		else if (obj->getType() == NUMBER)
		{
			printf("%f", ((Number*)obj)->getDoubleValue());
			printf("\n");
		}

		return NULL;
	}


	void regFunctions(langXState *state)
	{
		state->reg3rd("print", langX_print);
	}

}