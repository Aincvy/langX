#include "RegCoreModule.h"
#include "RegDefaultClasses.h"

namespace langX {

	//  注册 默认的类型
	int regDefault(langXState *state, XNameSpace* space) {

		regMath(state, space);
		regDateTime(state, space);
		regConvert(state, space);
		regThread(state, space);
		regApplication(state, space);
		regStringBuilder(state, space);

		return 0;
	}

}
