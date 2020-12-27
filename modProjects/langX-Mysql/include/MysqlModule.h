#pragma once


#include "langX/X3rdModule.h"
#include "langX/langX.h"

namespace langX {

	class MysqlModule: public X3rdModule
	{
	public:
		MysqlModule();
		~MysqlModule();

		// 初始化 mysql模块
		int init(langXState *);

		// 卸载 mysql模块
		int unload(langXState *);

	private:

	};


}