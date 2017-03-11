#pragma once
#include <map>
#include <string>
#include <list>
#include "Object.h"
#include "Function.h"
#include "StackTrace.h"
#include "Config.h"

namespace langX {
	class Environment;
	class XNameSpaceEnvironment;
	class Allocator;
	class ClassInfo;
	class langXObjectRef;
	class langXObject;
	class XNameSpace;
	class GlobalEnvironment;
	class ScriptEnvironment;
	class X3rdModule;
	class langXThreadMgr;

	/*
	  所有的脚本环境最后在释放内存。 
	*/


	// langX state
	class langXState
	{
	public:
		langXState();
		~langXState();


		// 换的 全局环境
		Environment *getGlobalEnv() const;
		// 获得脚本环境或者 命名空间环境  [类型视情况而定]
		Environment *getScriptOrNSEnv() const;

		// 注册一个第三方函数
		void reg3rd(const char *, X3rdFuncWorker worker);
		// 解除函数的注册
		void unreg3rd(const char *);

		//  注册一个类到 当前的脚本环境/命名空间环境
		void regClass(ClassInfo *);

		// 注册一个类 到 全局环境内。  在公共环境释放内存的时候会释放类信息， 所以不必手动释放
		void regClassToGlobal(ClassInfo *);

		Allocator &getAllocator() const;

		// NEW 一个对象 ，并不会执行对象的构造函数
		langXObject *newObject(const char *) const;

		// 获得类信息。  会先搜索当前脚本环境， 如果不存在， 则去搜索全局环境
		ClassInfo *getClass(const char *) const;

		// 获得一个命名空间[单一]， 如果该命名空间不存在， 则会添加一个进去 不能使用 a.b.c 这样的名字。。 因为不会解析出来
		XNameSpace *singleGetNameSpaceOrCreate(const char *);

		// 获得命名空间[单一]   不能使用 a.b.c 这样的名字。。 因为不会解析出来
		XNameSpace *singleGetNameSpace(const char *);

		// 获得命名空间， 支持 a.b.c
		XNameSpace *getNameSpace(const char *);

		// 获得一个命名空间，如果该命名空间不存在， 则会添加一个进去  支持 a.b.c
		XNameSpace *getNameSpaceOrCreate(const char *);

		void changeNameSpace(XNameSpace *);

		// 切换到指定的脚本环境上 [只切换环境]
		void newScriptEnv(ScriptEnvironment *);

		// 执行一个脚本  该脚本会切换到指定文件的环境（如果之前有存在，则会切换到那个环境， 没有就new一个）
		// 返回 0 表示切换成功， 返回 -1 表示失败
		int doFile(const char *);

		// 包含一个文件  当前脚本上执行
		int includeFile(const char *);
		// require一个文件  
		int requireFile(const char *);
		//
		int require_onceFile(const char *);

		// 是否执行过这个脚本
		bool isDidScript(const char  *);
		// 这个这个文件名到已执行过的脚本里面
		void addToDidScripts(const char *);

		// 获得正在解析文件的绝对路径
		const char * getParsingFile() const;

		// 碰到了一个文件的 eof 符号
		void fileEOF();

		// 加载一个模块 ,成功返回 0 ， 失败返回 -1
		int loadModule(const char *path);

		// 从文件中加载配置
		int loadConfig(const char *path);

		// 是否正在销毁中
		bool isDisposing() const;

	private:
		// 全局环境
		GlobalEnvironment *m_global_env = nullptr;
		
		// 当前的脚本环境， 可能是一个脚本环境， 可能是一个命名空间环境
		Environment *m_script_env = nullptr;
		Allocator  *m_allocator = nullptr;
		ConfigX m_config;

		std::map<std::string, XNameSpace*> m_namespace_map;
		//  执行过文件列表
		std::list<std::string> m_didScripts;
		//  正在执行文件的栈
		std::list<char*> m_doing_files;
		//  正在执行的脚本环境的栈 
		std::list<ScriptEnvironment*> m_doing_script_envs; 
		//  k:  脚本文件绝对路径，  v: 脚本环境.  仅供 require_once 使用
		std::map<std::string, ScriptEnvironment*> m_script_env_map;
		// 加载完成的动态库
		std::map<void*, X3rdModule*> m_load_libs;

		// 正在解析的文件的绝对路径
		char * m_parsing_file = NULL;

		bool m_yy_parsing = false;

		

		bool m_disposing = false;

		langXThreadMgr* m_thread_mgr;

		
	};
}