#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Environment.h"
#include "Allocator.h"

namespace langX {
	class langXState
	{
	public:
		langXState();
		~langXState();

		void putObject(const char* , Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);

		/* 生成一个新的环境，并将当前环境设置为该环境的父级环境， 然后将该环境设置为当前环境 */
		Environment *newEnv();
		/* 将环境退回一级，如果当前只有一级环境，则什么也不做 */
		void backEnv();

		Environment *getCurrentEnv() const;
		Environment *getGlobalEnv() const;

		Allocator &getAllocator() const;

	private:
		// 全局环境
		Environment *m_global_env = nullptr;
		Environment *m_current_env = nullptr;
		Allocator  *m_allocator = nullptr;

	};
}