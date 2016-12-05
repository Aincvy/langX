#pragma once

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"

namespace langX {

	class JsonModule : public X3rdModule
	{
	public:
		JsonModule();
		~JsonModule();


		// 初始化 json模块
		int init(langXState *);

		// 卸载 json模块
		int unload(langXState *);

	private:

	};


}

