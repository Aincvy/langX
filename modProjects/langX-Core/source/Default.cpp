#include "../include/RegCoreModule.h"
#include "../include/RegDefaultClasses.h"

namespace langX {


	int regDeafult(langXState *state, XNameSpace* space) {

		regMath(state, space);

		return 0;
	}

}