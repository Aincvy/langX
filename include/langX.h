#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Function.h"

namespace langX {
	class Environment;
	class Allocator;

	class langXState
	{
	public:
		langXState();
		~langXState();

		void putObject(const char* , Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);

		/* 生成一个新的环境，并将当前环境设置为该环境的父级环境， 然后将该环境设置为当前环境 */
		Environment* newEnv();
		// 将参数作为 当前环境， 并将原当前环境至为 参数的 父级环境
		Environment* newEnv(Environment *);
		/* 将环境退回一级，如果当前只有一级环境，则什么也不做 
		  如果退回上级环境， 当前环境内的所有变量的内存都将会被释放 */
		void backEnv();

		Environment *getCurrentEnv() const;
		Environment *getGlobalEnv() const;

		// 注册一个第三方函数
		void reg3rd(const char *, X3rdFuncWorker worker);
		// 解除函数的注册
		void unreg3rd(const char *);

		Allocator &getAllocator() const;

	private:
		// 全局环境
		Environment *m_global_env = nullptr;
		Environment *m_current_env = nullptr;
		Allocator  *m_allocator = nullptr;

	};
}