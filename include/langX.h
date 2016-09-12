#pragma once
#include <map>
#include <string>
#include <list>
#include <queue>
#include "Object.h"
#include "Function.h"
#include "StackTrace.h"

namespace langX {
	class Environment;
	class XNameSpaceEnvironment;
	class Allocator;
	class ClassInfo;
	class langXObjectRef;
	class langXObject;
	class XNameSpace;
	class GlobalEnvironment;

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
		// 并不会将参数赋值， 而是 new 一个 环境的桥接环境
		Environment* newEnv2(Environment *);
		/* 将环境退回一级，如果当前只有一级环境，则什么也不做 
		  如果退回上级环境， 当前环境内的所有变量的内存都将会被释放. 当前环境也会被释放 */
		void backEnv();
		//  是否对当前环境的指针进行 delete 操作
		void backEnv(bool);

		Environment *getCurrentEnv() const;
		Environment *getGlobalEnv() const;

		// 获得最近的一个对象环境 (必定会返回一个 ObjectBridgeEnv!)
		Environment *getNearestObjectEnv() const;

		// 注册一个第三方函数
		void reg3rd(const char *, X3rdFuncWorker worker);
		// 解除函数的注册
		void unreg3rd(const char *);

		//  注册一个类到 当前的脚本环境/命名空间环境
		void regClass(ClassInfo *);

		// 注册一个类 到 全局环境内。  在公共环境释放内存的时候会释放类信息， 所以不必手动释放
		void regClassToGlobal(ClassInfo *);

		Allocator &getAllocator() const;

		// 获得当前的调用栈
		StackTrace & getStackTrace();

		// 打印调用堆栈信息  会优先输出最近的那个信息
		void printStackTrace() const;

		// 丢出一个 异常。  参数的内存在执行结束之后会被释放
		void throwException(langXObjectRef *);

		// NEW 一个对象 ，并不会执行对象的构造函数
		langXObject *newObject(const char *) const;

		// 获得类信息。  会先搜索当前脚本环境， 如果不存在， 则去搜索全局环境
		ClassInfo *getClass(const char *) const;

		// 获得一个命名空间， 如果该命名空间不存在， 则会添加一个进去
		XNameSpace *getNameSpace(const char *);

		void changeNameSpace(XNameSpace *);

		// 建立一个新的脚本环境
		void newScriptEnv(const char *);

		// 执行一个脚本  [并不会更改当前的脚本环境]  这个函数会在当前环境上执行别的脚本
		// 返回 0 表示切换成功， 返回 -1 表示失败
		int doFile(const char *);

		// 是否执行过这个脚本
		bool isDidScript(const char  *);
		// 这个这个文件名到已执行过的脚本里面
		void addToDidScripts(const char *);

		void pushDoingFile(const char *);

		const char* popDoingFile();

	private:
		// 全局环境
		GlobalEnvironment *m_global_env = nullptr;
		Environment *m_current_env = nullptr;
		Environment *m_script_env = nullptr;
		Allocator  *m_allocator = nullptr;
		StackTrace m_stacktrace;

		std::map<std::string, XNameSpace*> m_namespace_map;
		//  执行过文件列表
		std::list<std::string> m_didScripts;
		//  正在执行文件的队列
		std::queue<const char*> m_doing_queue;

		int m_current_deep = 0;

	};
}