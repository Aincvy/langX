#pragma once

#include "langX/X3rdModule.h"

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


int loadModule(langX::X3rdModule *& mod);
