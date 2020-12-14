#pragma once

#include "langX.h"

/*
 * @date 2016-10-30
 * @author hideDragon
 *
 * 首先使用 loadModule 函数加载 模块。  加载好之后，  调用模块的 init 函数初始化模块
 */

namespace langX {

	// 日志对象
	class Logger;

	// 第三方模块。  所有的外部模块应该继承这个类
	class X3rdModule : public langXModule
	{
	public:
		X3rdModule();
		virtual ~X3rdModule();

		// 初始化模块 . 初始化成功返回0 ，失败返回 -1
		virtual int init(langXState *) override;

		// 卸载模块，  卸载成功返回 0 ， 失败返回 -1
		virtual int unload(langXState *) override;

		// 动态库的 .so 文件的位置
		void setSoObj(void *soObj);
		void * getSoObj() const override;

		/**
		 * 获取当前 module 的日志 输出类
		 * @return
		 */
		Logger* getLogger();

		/**
		 * 初始化 日志相关的类
		 */
        void initLogger(langXState *state);


        // 获取这个模块的名字
        const char * getName() const override;
        // 设置当前模块的名字，  会复制参数指向的内存
        void setName(const char *);

        virtual const char* getDescription() const override;

        virtual const char *getAuthor() const override;

        virtual const char *getVersion() const override;

        virtual const char *getRepository() const override;

        virtual const char *getEntrypoint() const override;

        ModuleType getModuleType() const override;

	private:

		// 模块的名字
		char * m_name = nullptr;
		// 加载的模块的 so 文件的指针
		void * m_soObj = nullptr;

		// 释放上一个name的内存
		void freeLastName();
	};


}


// 加载模块  这个函数基本不会主动调用 
// 加载成功 应该返回 0 ， 失败返回-1
extern "C" int loadModule(langX::X3rdModule *& mod);

typedef int(*LoadModuleFunPtr)(langX::X3rdModule *& mod);