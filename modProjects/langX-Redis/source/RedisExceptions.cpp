#include "../include/RegRedisModule.h"

#include "../../../include/Exception.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/Environment.h"


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
