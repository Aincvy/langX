#include "../include/RegCoreModule.h"
#include "../include/RegDefaultClasses.h"

namespace langX {

	//  注册 默认的类型
	int regDeafult(langXState *state, XNameSpace* space) {

		regMath(state, space);
		regDateTime(state, space);
		regConvert(state, space);

		return 0;
	}

}