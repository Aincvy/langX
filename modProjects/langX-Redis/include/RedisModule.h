#pragma once

#include "../../../include/X3rdModule.h"

namespace langX {

	class langXObject;
	class Object;

	class RedisModule : public X3rdModule {
	public:
		RedisModule();
		~RedisModule();

		int init(langXState *);

		virtual int unload(langXState *);

		private:
	};

}

// lang x  会调用这个方法尝试获取一个 mod 
int loadModule(langX::X3rdModule *& mod);
