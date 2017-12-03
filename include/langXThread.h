#pragma once

#include "StackTrace.h"

#include <string>
#include <map>
#include <thread>
#include <mutex>

namespace langX {

	class Environment;
	class Object;
	class langXObjectRef;
	class Function;
	struct Node;
	struct NodeFileInfo;
	struct NodeLink;

	// 线程状态
	enum langXThreadStatus {
		// 运行中
		Running = 101,
		// 睡眠
		Sleep,
		// 就绪状态
		Runnable,
	};
	
	// 调用栈的栈顶状态 
	struct StackTraceTopStatus{
		
		/* 设计成short类型值 主要是用于嵌套 比如函数内调用函数 就会使inFunction的值变成2  */
		
		// 是否在循环内
		short inLoop = 0 ;
		// 是否在函数内
		short inFunction = 0 ;
		// 是否在switch 内
		short inSwitch = 0 ;
		// 是否在异常内  发生异常之后会累加此值，遇到 try-catch 则会减少1
		short inException = 0;
		// 是否执行了 continue 
		short inContinue = 0;
		// 在case 的时候是否需要计算case 的条件
		short inCaseNeedCon = 0;

		// 是否内部执行中回退了节点， 这样会导致最外层的curLink 变量失效
		bool backInExec = false;   
		// 正在执行的函数的根节点
		Node * funcRootNode = nullptr;
	};
	

	// 线程信息
	class langXThread
	{
	public:
		// id 分配过来的线程id
		langXThread(int id);
		~langXThread();

		// 获得当前的调用栈
		StackTrace & getStackTrace();

		// 获得这个线程的名字
		const char * getName() const;
		// 设置这个线程的名字
		void setName(const char *);
		
		// 设置这个线程的状态
		langXThreadStatus getStatus() const;
		// 获得这个线程的状态
		void setStatus(langXThreadStatus );

		// 设置是否在循环内  true:是，false  否
		void setInLoop(bool);
		// 当前是否在循环内
		bool isInLoop();
		// 
		void setInFunction(bool);
		bool isInFunction();
		void setInSwitch(bool);
		bool isInSwitch();
		void setInException(bool);
		bool isInException();
		void setInCaseNeedCon(bool);
		bool isInCaseNeedCon();
		void setBackInExec(bool);
		bool isBackInExec();
		void setFuncRootNode(Node*);
		Node* getFuncRootNode();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);
		Function * getFunction(const std::string &);
		

		// 丢出一个 异常。  参数的内存在执行结束之后会被释放
		void throwException(langXObjectRef *);


		// 获得 当前环境
		Environment *getCurrentEnv() const;

		// 打印调用堆栈信息  会优先输出最近的那个信息
		void printStackTrace() const;

		/* 生成一个新的环境，并将当前环境设置为该环境的父级环境， 然后将该环境设置为当前环境 */
		Environment* newEnv();
		// 将参数作为 当前环境， 并将原当前环境至为 参数的 父级环境
		Environment* newEnv(Environment *);
		// 并不会将参数赋值， 而是 new 一个 环境的桥接环境
		Environment* newEnv2(Environment *);
		/* 将环境退回一级，如果当前只有一级环境，则什么也不做
		如果退回上级环境， 当前环境内的所有变量的内存都将会被释放. 当前环境也会被释放 */
		void backEnv();
		//  是否对当前环境的指针进行 delete 操作 .  参数为false 的时候， 不进行delete 操作
		void backEnv(bool);

		// 获得最近的一个对象环境 (必定会返回一个 ObjectBridgeEnv!)
		Environment *getNearestObjectEnv() const;

		// 获得函数的返回值
		Object * getFunctionResult();
		// 设置函数的返回值   函数内部会自动尝试获得该值的副本
		void setFunctionResult(Object *);
		
		// 获得正在执行节点的文件信息
		NodeFileInfo getCurrentNodeFileInfo();

		// 获得丢出来的那个对象
		langXObjectRef *getThrownObj();

		// 
		bool isMainThread();
		void setMainThread(bool);

		// 杀死当前线程
		void kill();

		//  推进当前的执行节点到一个新的节点
		NodeLink * beginExecute(Node *);   
		//  bool:  在执行结束之后是否回退
		NodeLink * beginExecute(Node *,bool );
		// 结束执行
		void endExecute();
		// 初始化根节点
		NodeLink * initRootNode(Node *);
		// 获取当前正在执行的节点链路
		NodeLink * getCurrentExecute();

	private:

		// 线程id
		int m_thread_id;
		// 调用栈
		StackTrace m_stacktrace;
		// 这个线程的名字
		std::string m_name;

		langXThreadStatus m_thread_status;
		// 执行栈的栈顶状态
		StackTraceTopStatus m_exec_status;

		// 线程的当前环境
		Environment *m_current_env = nullptr;
		// 线程是否是主线程
		bool m_is_main_thread = false;

		int m_current_deep = 0;
		// 函数的返回值 | 可能用用不到这个值
		Object *m_function_result = nullptr;
		// 丢出来的那个对象
		langXObjectRef * m_thrown_obj = nullptr;
		//  执行节点的根节点
		NodeLink * executeRoot;        
		// 当前的执行节点
		NodeLink * currentExecute;     

		// 释放掉丢出的对象
		void freeThrownObj(); 
	};


	// 线程管理器
	class langXThreadMgr
	{
	public:
		langXThreadMgr();
		~langXThreadMgr();

		// 初始化 主线程信息
		void initMainThreadInfo();

		// 释放掉所有的线程信息
		void freeAllThreads();

		// 获得当前线程的对象
		langXThread *currentThread();

	private:
		
		// key: 从系统函数获取的线程id ,value: 线程对象
		std::map<std::thread::id, langXThread*> m_idmap;
		// key: 自身内部的线程id, value: 线程对象
		std::map<int, langXThread*> m_selfmap;
		
		// id 自增量
		int m_id_gen;
		// 用于id自增量的互斥锁
		std::mutex m_mutex_id_gen;


	};


	//  try-catch 的回调函数
	void  gTryCatchCB(langXObjectRef *obj);
}