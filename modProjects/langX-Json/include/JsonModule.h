#pragma once

#include "langX/X3rdModule.h"
#include "langX/langX.h"

namespace langX {

	class JsonModule : public X3rdModule
	{
	public:
		JsonModule();
		~JsonModule();

		int init(langXState *);

		int unload(langXState *);

	private:

	};


}

