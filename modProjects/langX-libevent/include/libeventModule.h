#pragma once

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"

namespace langX {

	class libeventModule : public X3rdModule
	{
	public:
		libeventModule();
		~libeventModule();

		// 初始化 libevent模块
		int init(langXState *);

		// 卸载 libevent模块
		int unload(langXState *);

	private:

	};

}