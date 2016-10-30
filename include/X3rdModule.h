#pragma once

/*
 * @date 2016-10-30
 * @author hideDragon
 *
 * 首先使用 loadModule 函数加载 模块。  加载好之后，  调用模块的 init 函数初始化模块
 */

namespace langX {

	class langXState;

	// 第三方模块。  所有的外部模块应该继承这个类
	class X3rdModule
	{
	public:
		X3rdModule();
		virtual ~X3rdModule();

		// 初始化模块 . 初始化成功返回0 ，失败返回 -1
		virtual int init(langXState *);

		// 卸载模块，  卸载成功返回 0 ， 失败返回 -1
		virtual int unload(langXState *);

	private:

	};


}


// 加载模块  这个函数基本不会主动调用 
// 加载成功 应该返回 0 ， 失败返回-1
extern "C" int loadModule(langX::X3rdModule *& mod);

typedef int(*LoadModuleFunPtr)(langX::X3rdModule *& mod);