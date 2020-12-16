#pragma once

#include "../../../include/X3rdModule.h"
#include "../../../include/langX.h"

// 重置一个 3rd object 属性
#define RESET_3RD_OBJECT(args) args.object->set3rdObj(nullptr)

// 用于快速得转换 3rdObject 成一个  struct event_base*
#define EVENT_BASE_PTR(args) (struct event_base*)args.object->get3rdObj()

#define MY_TIMER_PTR(args) (struct MyTimer*)args.object->get3rdObj()

// 检测参数是否是一个实例在调用
#define CHECK_OBJECT_NOT_NULL(args, msg) \
if (args.object == nullptr) { \
    moduleLogger->error("%s! NO OBJ!", msg); \
    return nullptr; \
} void(0)

#define CHECK_ARGS_SIZE(args, num) \
if (args.index < num) { \
    return nullptr; \
} void(0)

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

		const char * getName() const override;

		const char * getVersion() const override;

		const char * getRepository() const override;

		const char * getAuthor() const override;

		const char * getDescription() const override;

		const char * getEntrypoint() const override;

	private:

	};

	extern libeventModule* module;
	extern Logger* moduleLogger;

}