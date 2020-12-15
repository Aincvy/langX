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
	class GlobalEnvironment;
	class ScriptEnvironment;
	class XNameSpaceEnvironment;

	class Allocator;
	class ClassInfo;
	class langXObjectRef;
	class langXObject;
	class XNameSpace;
	class langXThreadMgr;
	class langXThread;
	class LogManager;
	class Logger;

	class X3rdModule;
	class ScriptModule;
	class langXModule;


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

		// 注册一个第三方函数 到全局环境里面
		void reg3rd(const char *, X3rdFuncWorker worker);
		// 解除函数的注册
		void unreg3rd(const char *);

		//  注册一个类到 当前的脚本环境/命名空间环境
		void regClass(ClassInfo *);

		// 注册一个类 到 全局环境内。  在公共环境释放内存的时候会释放类信息， 所以不必手动释放
		void regClassToGlobal(ClassInfo *);

		// NEW 一个对象 ，并不会执行对象的构造函数
		langXObject *newObject(const char *) const;

		// 获得类信息。  会先搜索当前脚本环境， 如果不存在， 则去搜索全局环境
		ClassInfo *getClass(const char *) const;

		// 根据类的全名获取一个类的信息
		ClassInfo *getClassByFullName(const char *);

		// 获得一个命名空间[单一]， 如果该命名空间不存在， 则会添加一个进去 不能使用 a.b.c 这样的名字。。 因为不会解析出来
		XNameSpace *singleGetNameSpaceOrCreate(const char *);

		// 获得命名空间[单一]   不能使用 a.b.c 这样的名字。。 因为不会解析出来
		XNameSpace *singleGetNameSpace(const char *);

		// 放一个命名空间到 langXState 里面
		void putNameSpace(const char*, XNameSpace *);

		// 获得命名空间， 支持 a.b.c
		XNameSpace *getNameSpace(const char *);

		// 获得一个命名空间，如果该命名空间不存在， 则会添加一个进去  支持 a.b.c
		XNameSpace *getNameSpaceOrCreate(const char *);

		void changeNameSpace(XNameSpace *);

		// 切换到指定的脚本环境上 [只切换环境]
		void newScriptEnv(ScriptEnvironment *);

		/**
		 * 回退一个脚本空间
		 * @param freeEnv  true: 释放脚本空间的环境， false: 不释放
		 */
		void backScriptEnv(bool freeEnv);

		// 执行一个脚本  该脚本会切换到指定文件的环境（如果之前有存在，则会切换到那个环境， 没有就new一个）
		// 返回 0 表示切换成功， 返回 -1 表示失败
		int doFile(const char *);

		/**
		 * 执行一个字符串
		 * @param content
		 * @return
		 */
		int doString(const char *content);

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

		/**
		 * 加载一个模块 ,成功返回 0 ， 失败返回 -1
		 * @param path
		 * @return -1 表示打开动态库失败， -2表示找不到 loadModule 函数， -3 表示加载module失败 其他非0结果为 module的初始化结果
		 */
		int loadModule(const char *path);

		/**
		 * 从文件中加载配置  | 次方法 目前越等于初始化 方法
		 * @param path
		 * @return
		 */
		int loadConfig(const char *path);

		// 是否正在销毁中
		bool isDisposing() const;

		// 返回当前线程信息
		langXThread* curThread() const;

		// 获取当前正在使用中的配置
		const ConfigX & getConfig() const;

		// 是否加载了某个模块
		bool isLoadModule(const char *) const ;

		// 设置是否正在解析中
		void setYYParsing(bool);

		// 设置程序的启动参数
		void setStartArg(int argc, char *argv[]);

		// 获取启动参数列表的长度
		int getArgc();
		// 获取启动参数的实际值
		char** getArgv();

		/**
		 * 获取日志管理器
		 * @return
		 */
		LogManager* getLogManager() const;

		/**
		 * 加载一个模块
		 * @param path   可以是一个文件夹， 或者是一个 （脚本包， 目前还没有实现相关内容）
		 * @return   加载成功返回一个 指针， 否则返回一个 nullptr
		 */
		ScriptModule* loadScriptModule(const char* path);

		/**
		 * 检测一下某个线程正在执行得文件是否结束了
		 * @param thread
		 */
		void checkEndOfFile(langXThread *thread);

		/**
		 * 输出 module 得日志到 module.log 里面
		 * @param module
		 */
		void logModule(langXModule * module);


	private:
		// 全局环境
		GlobalEnvironment * m_global_env = nullptr;

		// 当前的脚本环境， 可能是一个脚本环境， 可能是一个命名空间环境
		Environment *m_script_env = nullptr;
		// 配置
		ConfigX m_config;
		// 日志管理器
		LogManager *m_log_manager = nullptr;

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
		std::map<std::string, langXModule*> m_load_libs;


		// 正在解析的文件的绝对路径
		char * m_parsing_file = nullptr;
		// 使用 include 关键字包含脚本的深度
		int includeDeep = 0;

		bool m_yy_parsing = false;

		bool m_disposing = false;

		// 启动的参数信息
		int startArgSize = 0;
		char **startArgValues = nullptr;

		langXThreadMgr* m_thread_mgr = nullptr;

		/**
		 * 如果没有在parse 就开始parse
		 */
		void startParseIfNot();

		/**
		 * loadModule OSX/Linux 版本得实现
		 * @param path
		 * @return
		 */
		int loadModuleOSX(const char* path);

	};

	/**
	 * 模块类型
	 */
	enum ModuleType{
		// 脚本模块
		Script,
		// 第三方 一般是cpp得模块
		X3rd,
		// 自定义得类型， 这个 目前没有使用， 仅占位使用
		Custom,
	};


	/**
	 * 表示一个 langX 得模块  | cpp 编写得模块和 langX脚本编写得模块都会继承自此类
	 */
	class langXModule{

	public:

		langXModule() = default;
		virtual ~langXModule() = default;


		/**
		 * 获取当前模块得名字
		 * @return
		 */
		virtual const char* getName() const = 0;

		/**
		 * 获取当前模块得 描述信息
		 * @return
		 */
		virtual const char* getDescription() const = 0;

		/**
		 * 获取当前模块得作者信息
		 * @return
		 */
		virtual const char* getAuthor() const = 0;

		/**
		 * 获取当前模块得版本信息
		 * @return
		 */
		virtual const char* getVersion() const = 0;

		/**
		 * 获取当前模块得 仓库信息
		 * @return
		 */
		virtual const char* getRepository() const = 0;

		/**
		 * 获取当前模块得入口点
		 * @return
		 */
		virtual const char* getEntrypoint() const = 0;

		/**
		 * 获取模块得类型
		 * @return
		 */
		virtual ModuleType getModuleType() const = 0;

		/**
		 * 卸载 模块
		 * @return
		 */
		virtual int unload(langXState *) = 0;

		/**
		 * 初始化模块
		 * @return
		 */
		virtual int init(langXState *) = 0;

		/**
		 * 获取 动态库得指针
		 * @return
		 */
		virtual void * getSoObj() const = 0;


	protected:

		// 日志对象
		Logger *m_logger = nullptr;

		// 当前得脚本模块是哪个 m_state 加载得
		langXState* m_state = nullptr;

	};


	/**
	 * include 一个脚本
	 * @param filename  文件路径
	 */
	void includeFile(const char *filename);

	/**
	 * require  一个脚本
	 * @param filename   文件路径
	 */
    void requireFile(const char *filename);

    /**
     * require once 一个脚本
     * @param filename   文件路径
     */
    void requireOnceFile(const char *filename);

}
