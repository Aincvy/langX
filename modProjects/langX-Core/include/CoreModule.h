#pragma once

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"

namespace langX {

	class CoreModule : public X3rdModule
	{
	public:
		CoreModule();
		~CoreModule();

		// 初始化 core模块
		int init(langXState *);

		// 卸载c ore模块
		int unload(langXState *);

	private:

	};


}
