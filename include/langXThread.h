#pragma once

#include "StackTrace.h"

#include <map>

namespace langX {

	// 线程信息
	class langXThread
	{
	public:
		langXThread();
		~langXThread();

		// 获得当前的调用栈
		StackTrace & getStackTrace();

	private:

		// 线程id
		int m_thread_id;
		// 调用栈
		StackTrace m_stacktrace;



	};


	// 线程管理器
	class langXThreadMgr
	{
	public:
		langXThreadMgr();
		~langXThreadMgr();

	private:

	};


}