#pragma once

#include "../../../include/X3rdModule.h"

namespace langX {



	class PythonModule : public X3rdModule
	{
	public:
		PythonModule();
		~PythonModule();

		int init(langXState *);

		virtual int unload(langXState *);

	private:

	};

}

int loadModule(langX::X3rdModule *& mod);