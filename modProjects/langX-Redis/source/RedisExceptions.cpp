#include "../include/RegRedisModule.h"

#include "langX/Exception.h"
#include "langX/ClassInfo.h"
#include "langX/Environment.h"


namespace langX {


	int regRedisExceptions(langXState * state, XNameSpace * space)
	{
		ClassInfo * exception = state->getGlobalEnv()->getClassSelf("Exception");
		
		ClassInfo *redisCommonException = new ClassInfo("RedisCommonException");
		redisCommonException->setParent(exception);
		space->putClass(redisCommonException);

		return 0;
	}

}
