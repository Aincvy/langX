#pragma once

#include "StackTrace.h"

#include <string>
#include <map>

namespace langX {

	// 线程状态
	enum langXThreadStatus{
		// 运行中
		RUNNING = 101 ,
		// 睡眠
		SLEEP  ,
		// 就绪状态
		Runnable ,
	}
	
	// 调用栈的栈顶状态 
	struct StackTraceTopStatus{
		
		/* 设计成short类型值 主要是用于嵌套 比如函数内调用函数 就会使inFunction的值变成2  */
		
		// 是否在循环内
		short inLoop = 0 ;
		// 是否在函数内
		short inFunction = 0 ;
		// 是否在switch 内
		short inSwitch = 0 ;
	}
	

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
		// 这个线程的名字
		std::string m_name;


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