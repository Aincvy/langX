#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iterator>
#include <vector>
#include <string>
#include "../include/ClassInfo.h"
#include "../include/Config.h"
#include "../include/langX.h"
#include "../include/Object.h"
#include "../include/Number.h"
#include "../include/Environment.h"
#include "../include/Allocator.h"
#include "../include/StackTrace.h"
#include "../include/ExecNode.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/YLlangX.h"
#include "../include/Exception.h"
#include "../include/Function.h"
#include "../include/XNameSpace.h"
#include "../include/X3rdModule.h"
#include "../include/langXThread.h"
#include "../include/LogManager.h"

#ifdef WIN32
//  win32 库
#else
// linux 库
#include <dlfcn.h>
#endif // WIN32

// 切换缓冲区到 文件指针
extern void pushBuffer(FILE *fp);
extern int yyparse(void);

namespace langX {

	langXState::langXState()
	{
		this->m_global_env = new GlobalEnvironment();
		this->m_global_env->setParent(NULL);
		this->m_global_env->setDeep(0);
		this->m_disposing = false;
		this->m_thread_mgr = new langXThreadMgr();
		this->m_thread_mgr->initMainThreadInfo();
    this->m_log_manager = new LogManager();
    this->m_log_manager->init();

	}

	langXState::~langXState()
	{
		this->m_disposing = true;
    delete this->m_log_manager;
		// 清理内存对象
		Allocator::freeAllObjs();

		for (auto i = this->m_script_env_map.begin(); i != this->m_script_env_map.end(); i++)
		{
			delete (i->second);
		}

		this->m_script_env_map.clear();

		// 清理命名空间
		for (std::map<std::string, XNameSpace*>::iterator i = this->m_namespace_map.begin(); i != this->m_namespace_map.end(); i++)
		{
			XNameSpace *p = i->second;
			delete p;
		}
		this->m_namespace_map.clear();

		delete this->m_global_env;
		this->m_global_env = nullptr;

		// 清理掉所有的线程
		this->m_thread_mgr->freeAllThreads();
		delete this->m_thread_mgr;
		
#ifdef WIN32
		
		// WIN32实现
#else
		// 清理加载的动态库
		for (auto it = this->m_load_libs.begin(); it != this->m_load_libs.end(); it++)
		{
			it->second->unload(this);
			dlclose(it->first);
		}
#endif

		this->m_load_libs.clear();
	}



	Environment * langXState::getGlobalEnv() const
	{
		return this->m_global_env;
	}

	Environment * langXState::getScriptOrNSEnv() const
	{
		return this->m_script_env;
	}

	void langXState::reg3rd(const char *name, X3rdFuncWorker worker)
	{
		X3rdFunction *func = new X3rdFunction();
		func->setName(name);
		func->setWorker(worker);
		func->setParamsList(NULL);
		func->setLangX(this);
		this->m_global_env->putFunction(name, func);
	}

	void langXState::unreg3rd(const char *name)
	{
		// do nothing now. 

	}

	void langXState::regClass(ClassInfo *c)
	{
		if (c == NULL)
		{
			return;
		}

		this->m_script_env->putClass(c->getName(), c);
	}

	void langXState::regClassToGlobal(ClassInfo *c)
	{
		if (c == NULL)
		{
			return;
		}

		this->m_global_env->putClass(c->getName(), c);
	}

	langXObject * langXState::newObject(const char * name) const
	{
		ClassInfo* classinfo = this->m_global_env->getClass(name);
		if (classinfo == NULL)
		{
			return NULL;
		}

		return classinfo->newObject();
	}

	ClassInfo * langXState::getClass(const char *name) const
	{
		ClassInfo * c = nullptr;
		if (this->m_script_env != nullptr)
		{
			c = this->m_script_env->getClass(name);
			if (c != nullptr)
			{
				return c;
			}
		}

		return this->m_global_env->getClass(name);
	}

	XNameSpace * langXState::singleGetNameSpaceOrCreate(const char *name)
	{
		if (this->m_namespace_map.find(name) != this->m_namespace_map.end())
		{
			return this->m_namespace_map[name];
		}

		XNameSpace *space = new XNameSpace(name);
		this->m_namespace_map[name] = space;
		return space;
	}

	XNameSpace * langXState::singleGetNameSpace(const char *name)
	{
		if (this->m_namespace_map.find(name) != this->m_namespace_map.end())
		{
			return this->m_namespace_map[name];
		}
		return nullptr;
	}

	XNameSpace * langXState::getNameSpace(const char *name)
	{
		std::string str = std::string(name);
		XNameSpace *space = NULL;

		auto dotIndex = str.find_first_of(".");

		while (dotIndex != std::string::npos)
		{
			std::string f = str.substr(0, dotIndex);
			str = str.substr(dotIndex + 1);
			dotIndex = str.find_first_of(".");

			// f is namespace name
			if (space == NULL)
			{
				space = singleGetNameSpace(f.c_str());
			}
			else {
				space = space->getNameSpace(f.c_str());
			}

			if (space == NULL)
			{
				return NULL;
			}
		}

		if (space == NULL)
		{
			space = singleGetNameSpace(str.c_str());
		}
		else {
			space = space->getNameSpace(str.c_str());
		}

		return space;
	}

	XNameSpace * langXState::getNameSpaceOrCreate(const char *name)
	{
		std::string str = std::string(name);
		XNameSpace *space = NULL;

		auto dotIndex = str.find_first_of(".");

		while (dotIndex != std::string::npos)
		{
			std::string f = str.substr(0, dotIndex);
			str = str.substr(dotIndex + 1);
			dotIndex = str.find_first_of(".");

			// f is namespace name
			if (space == NULL)
			{
				space = singleGetNameSpaceOrCreate(f.c_str());
			}
			else {
				space = space->getNameSpace2(f.c_str());
			}

			if (space == NULL)
			{
				return NULL;
			}
		}

		if (space == NULL)
		{
			space = singleGetNameSpaceOrCreate(str.c_str());
		}
		else {
			space = space->getNameSpace2(str.c_str());
		}

		return space;
	}

	void langXState::changeNameSpace(XNameSpace *s)
	{
		if (s == nullptr)
		{
			return;
		}

		this->m_script_env = new XNameSpaceEnvironment(s);
	}

	void langXState::newScriptEnv(ScriptEnvironment *env)
	{
		if (env == NULL)
		{
			return;
		}

		if (this->m_script_env == env) {
			return;
		}

		if (this->m_script_env != NULL && this->m_script_env->getType() == EnvironmentType::TScriptEnvironment)
		{
			this->m_doing_script_envs.push_front( (ScriptEnvironment*)this->m_script_env);
		}

		this->m_script_env = env;

	}

	int langXState::doFile(const char *filename)
	{
		if (filename == NULL)
		{
			return -1;
		}

    logger->info("do file: %s", filename);
		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			curThread()->throwException(newFileNotFoundException(filename)->addRef());
			return -1;
		}

		if (this->m_parsing_file != NULL)
		{
			this->m_doing_files.push_front(this->m_parsing_file);
			this->m_parsing_file = NULL;
		}

		auto a = std::find(m_didScripts.begin(), m_didScripts.end(), filename);
		if (a == m_didScripts.end())
		{
			m_didScripts.push_back(filename);
		}

		char tmp[1024] = { 0 };
		realpath(filename, tmp);

		this->m_parsing_file = strdup(tmp);

		auto b = this->m_script_env_map.find(tmp);
		if (b == this->m_script_env_map.end())
		{
			ScriptEnvironment * env = new ScriptEnvironment(tmp);
			env->setParent(this->m_global_env);
			this->m_script_env_map[tmp] = env;
			newScriptEnv(env);
		}
		else {
			newScriptEnv( b->second );
		}

		//printf("push file %s to lex buffer!\n" , tmp);

		pushBuffer(fp);

		if (!m_yy_parsing)
		{
			m_yy_parsing = true;
			yyparse();
		}

		return 0;
	}

	int langXState::includeFile(const char *filename)
	{

		if (filename == NULL)
		{
			return -1;
		}

		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			curThread()->throwException(newFileNotFoundException(filename)->addRef());
			return -1;
		}

		if (this->m_parsing_file != NULL)
		{
			this->m_doing_files.push_front(this->m_parsing_file);
			this->m_parsing_file = NULL;
		}

		this->m_parsing_file = strdup(filename);

		//printf("require file %s !\n", filename);

		pushBuffer(fp);

		if (!m_yy_parsing)
		{
			m_yy_parsing = true;
			yyparse();
		}

		return 0;
	}

	int langXState::requireFile(const char *filename)
	{
		if (filename == NULL)
		{
			return -1;
		}

    logger->debug("requireFile %s", filename);
		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			curThread()->throwException(newFileNotFoundException(filename)->addRef());
			return -1;
		}

		if (this->m_parsing_file != NULL)
		{
			this->m_doing_files.push_front(this->m_parsing_file);
			this->m_parsing_file = NULL;
		}


		char tmp[1024] = { 0 };
		realpath(filename, tmp);

		this->m_parsing_file = strdup(tmp);

		
		ScriptEnvironment * env = new ScriptEnvironment(tmp);
		env->setParent(this->m_global_env);
		
		// 如果当前环境是一个脚本环境， 则将新的玩家记录到原环境上
		if (this->m_script_env->getType() == EnvironmentType::TScriptEnvironment)
		{
			// 
			int i = ((ScriptEnvironment*)this->m_script_env)->addRequireFile(filename, env);
			if (i != 0)
			{
				delete env;
				env = NULL;
				char tmpMsg[2048] = { 0 };
				sprintf(tmpMsg, "require file %s error. code=%d", filename, i);
				curThread()->throwException(newException(tmpMsg)->addRef());
				return -1;
			}
		}
		// 将新的脚本环境 应用到当前环境上 
		newScriptEnv(env);

		//printf("push file %s to lex buffer!\n" , tmp);

		pushBuffer(fp);

		if (!m_yy_parsing)
		{
			m_yy_parsing = true;
			yyparse();
		}

		return 0;
	}

	int langXState::require_onceFile(const char * filename)
	{
		
		if (filename == NULL)
		{
			return -1;
		}

    logger->debug("require_onceFile %s ", filename);
		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			curThread()->throwException(newFileNotFoundException(filename)->addRef());
			return -1;
		}

		if (this->m_parsing_file != NULL)
		{
			this->m_doing_files.push_front(this->m_parsing_file);
			this->m_parsing_file = NULL;
		}

		auto a = std::find(m_didScripts.begin(), m_didScripts.end(), filename);
		if (a == m_didScripts.end())
		{
			m_didScripts.push_back(filename);
		}

		char tmp[1024] = { 0 };
		realpath(filename, tmp);

		this->m_parsing_file = strdup(tmp);


		ScriptEnvironment * env = NULL;
		auto b = this->m_script_env_map.find(tmp);
		if (b == this->m_script_env_map.end())
		{
			env = new ScriptEnvironment(tmp);
			env->setParent(this->m_global_env);
			this->m_script_env_map[tmp] = env;
		}
		else {
			env = b->second;
		}

		// 如果当前环境是一个脚本环境， 则将新的玩家记录到原环境上
		if (this->m_script_env->getType() == EnvironmentType::TScriptEnvironment)
		{
			// 
			((ScriptEnvironment*)this->m_script_env)->addRequireOnceFile(filename, env);
		}
		// 将新的脚本环境 应用到当前环境上 
		newScriptEnv(env);

		//printf("push file %s to lex buffer!\n" , tmp);

		pushBuffer(fp);

		if (!m_yy_parsing)
		{
			m_yy_parsing = true;
			yyparse();
		}

		return 0;
	}

	bool langXState::isDidScript(const char *f)
	{
		std::list<std::string>::iterator it = std::find(m_didScripts.begin(), m_didScripts.end(), f);

		if (it == m_didScripts.end())
		{
			return false;
		}

		return true;
	}

	void langXState::addToDidScripts(const char *f)
	{
		this->m_didScripts.push_back(f);
	}

	const char * langXState::getParsingFile() const
	{
		return this->m_parsing_file;
	}

	void langXState::fileEOF()
	{

		logger->debug("file %s eof!", m_parsing_file);
		free(this->m_parsing_file);
		this->m_parsing_file = NULL;

		if (this->m_doing_files.empty())
		{
			return;
		}


		char * p = this->m_doing_files.front();
		this->m_doing_files.erase(this->m_doing_files.begin());
		this->m_parsing_file = p;

		if (!m_doing_script_envs.empty())
		{
			ScriptEnvironment *scrEnv = m_doing_script_envs.front();
			m_doing_script_envs.erase(m_doing_script_envs.begin());

			newScriptEnv(scrEnv);
		}
		
	}

#ifdef WIN32
	int langXState::loadModule(const char * path) {
		// WIN32实现
		return -1;
	}
#else
	int langXState::loadModule(const char * path) {
		void *soObj = dlopen(path, RTLD_LAZY);
		if (soObj == NULL) {
			printf("dlopen err:%s.\n", dlerror());
			return -1;
		}

    logger->debug("load module: %s", path);
		LoadModuleFunPtr fptr = (LoadModuleFunPtr)dlsym(soObj, "loadModule");
		if (fptr == NULL) {
			return -1;
		}

		X3rdModule * mod = NULL;
		fptr(mod);

		if (mod == NULL) {
			return -1;
		}

		int ret = mod->init(this);

		this->m_load_libs[soObj] = mod;
    logger->debug("load module %s over", path);

		return ret;
	}
#endif

	

	int langXState::loadConfig(const char * path)
	{
    logger->debug("using config file %s", path);
		int a = this->m_config.loadFrom(path);
		if (a < 0)
		{
			return -1;
		}

		std::string &dir = this->m_config.getLibDir();
		std::vector<std::string> & paths = this->m_config.getLibPath();
		for (auto i = paths.begin(); i != paths.end(); i++)
		{
			std::string abc = dir + "/" +  (*i);
			a = this->loadModule(abc.c_str());
			if (a < 0)
			{
				return -1;
			}
		}

    logger->debug("load config file over.");
		return 0;
	}

	bool langXState::isDisposing() const
	{
		
		return this->m_disposing;
	}

	langXThread* langXState::curThread() const
	{
		return this->m_thread_mgr->currentThread();
	}

}
