#include "../include/RegRedisModule.h"

#include "../../../include/Exception.h"
#include "../../../include/ClassInfo.h"
#include "../../../include/Environment.h"


namespace langX {



	int regRedisExcceptions(langXState * state, XNameSpace * space)
	{
		ClassInfo * expection = state->getGlobalEnv()->getClassSelf("Exception");
		
		ClassInfo *redisCommonException = new ClassInfo("RedisCommonException");
		redisCommonException->setParent(expection);
		space->putClass(redisCommonException);

		return 0;
	}

}
