/*************************************************************************************//**
 *  @file       ZlibModule.h
 *
 *  @brief      Brief description of ZlibModule.h
 *
 *  @date       2018-02-28 19:05
 *         
 **************************************************************************************/

#include "langX/X3rdModule.h"

#ifndef ZLIBMODULE_H
#define ZLIBMODULE_H

namespace langX{

	class langXObject;
	class Object;

	class ZlibModule : public X3rdModule {

	public:
		ZlibModule();
		~ZlibModule();

		int init(langXState *);

		virtual int unload(langXState *);

	private:

	};

}

int loadModule(langX::X3rdModule *& mod);

#endif /* !ZLIBMODULE_H */

