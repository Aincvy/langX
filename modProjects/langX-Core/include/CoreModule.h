#pragma once

#include "X3rdModule.h"
#include "langX.h"

/**
 * core 模块得版本
 */
#define CORE_MODULE_VERSION "0.0.1"

namespace langX {

	class CoreModule : public X3rdModule
	{
	public:
		CoreModule();
		~CoreModule();

		// 初始化 core模块
		int init(langXState *) override;

		// 卸载c ore模块
		int unload(langXState *) override;

		const char * getName() const override;

		const char * getAuthor() const override;

        const char * getVersion() const override;

		const char * getDescription() const override;

		const char * getRepository() const override;

	private:

	};

    extern CoreModule* coreModule;
    extern Logger* coreModuleLogger;

}
