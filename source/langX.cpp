#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iterator>
#include "../include/ClassInfo.h"
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

#ifdef WIN32
//  win32 库
#else
// linux 库
#include <dlfcn.h>
#endif // WIN32

// 切换缓冲区到 文件指针
extern void pushBuffer(FILE *fp);
extern int yyparse(void);

// 释放环境内存
void freeEnv(langX::Environment **env) {

	if (env == NULL || (*env) == NULL)
	{
		return;
	}

	langX::Environment *p = (*env);
	switch (p->getType())
	{
	case langX::TDefaultEnvironment:
		delete (langX::DefaultEnvironment*) p;
		break;
	case	langX::TGlobalEnvironment:
		delete (langX::GlobalEnvironment*) p;
		break;
	case	langX::TScriptEnvironment:
		delete (langX::ScriptEnvironment*) p;
		break;
	case	langX::TXNameSpaceEnvironment:
		delete (langX::XNameSpaceEnvironment*) p;
		break;
	case	langX::TClassBridgeEnv:
		delete (langX::ClassBridgeEnv*) p;
		break;
	case	langX::TObjectBridgeEnv:
		delete (langX::ObjectBridgeEnv*) p;
		break;
	case	langX::TTryEnvironment:
		delete (langX::TryEnvironment*) p;
		break;
	case	langX::TEnvironmentBridgeEnv:
		delete (langX::EnvironmentBridgeEnv*) p;
		break;
	default:
		break;
	}

	*env = NULL;
}

namespace langX {

	void  gTryCatchCB(langXObjectRef *obj) {
		Function *func = obj->getFunction("printStackTrace");
		if (func != NULL)
		{
			if (func->is3rd())
			{
				X3rdArgs _3rdArgs;
				_3rdArgs.object = obj->getRefObject();
				_3rdArgs.index = 0;
				_3rdArgs.arrayRef = NULL;
				X3rdFunction *f = (X3rdFunction*)func;
				f->call(_3rdArgs);
			}
			else {
				func->call();
			}
		}
	}

	langXState::langXState()
	{
		XNameSpace *s = new XNameSpace("$NoName1");
		this->m_namespace_map[s->getName()] = s;
		this->m_global_env = new GlobalEnvironment();
		this->m_global_env->setParent(NULL);
		this->m_global_env->setDeep(0);
		TryEnvironment *tryEnv = new TryEnvironment();
		tryEnv->setParent(this->m_global_env);
		tryEnv->setCatchCB(gTryCatchCB);
		tryEnv->setDeep(1);
		this->m_current_env = tryEnv;
		this->m_current_deep = 1;
		this->m_allocator = new Allocator();

		this->m_stacktrace.newFrame(NULL, NULL, "<startFrame>");
	}

	langXState::~langXState()
	{
		for (std::map<std::string, XNameSpace*>::iterator i = this->m_namespace_map.begin(); i != this->m_namespace_map.end(); i++)
		{
			XNameSpace *p = i->second;
			delete p;
		}
		this->m_namespace_map.clear();

		delete this->m_allocator;

		backToDeep1Env();

		while (this->m_current_env != NULL && this->m_current_env->getParent() != NULL)
		{
			backEnv();
		}

		//  下面那条语句的当前环境就是  m_global_env  ，所以无需释放 m_global_env
		freeEnv(&this->m_current_env);

		for (auto i = this->m_script_env_map.begin(); i != this->m_script_env_map.end(); i++)
		{
			delete (i->second);
		}

		this->m_script_env_map.clear();
	}

	void langXState::putObject(const char * name, Object *obj)
	{
		this->m_current_env->putObject(name, obj);
	}

	void langXState::putObject(const std::string &name, Object *obj)
	{
		this->m_current_env->putObject(name, obj);
	}
	Object * langXState::getObject(const std::string &name)
	{
		return this->m_current_env->getObject(name);
	}



	Environment * langXState::newEnv()
	{
		Environment *env = new DefaultEnvironment();
		env->setParent(this->m_current_env);
		env->setDeep((++this->m_current_deep));
		this->m_current_env = env;
		return env;
	}

	Environment * langXState::newEnv(Environment *env)
	{
		if (env == NULL)
		{
			return NULL;
		}

		env->setParent(this->m_current_env);
		env->setDeep((++this->m_current_deep));
		this->m_current_env = env;
		return env;
	}

	Environment * langXState::newEnv2(Environment *env)
	{
		if (env == NULL)
		{
			return NULL;
		}

		EnvironmentBridgeEnv *bEnv = new EnvironmentBridgeEnv(env);
		bEnv->setParent(this->m_current_env);
		bEnv->setDeep((++this->m_current_deep));
		this->m_current_env = bEnv;
		return bEnv;
	}

	void langXState::backEnv()
	{
		backEnv(true);
	}

	void langXState::backEnv(bool flag)
	{
		Environment *env = this->m_current_env->getParent();
		if (env == NULL)
		{
			return;
		}
		if (flag)
		{
			//  子类
			freeEnv(&this->m_current_env);
			//this->m_current_env = NULL;
		}
		this->m_current_deep--;
		this->m_current_env = env;
	}

	Environment * langXState::getCurrentEnv() const
	{
		return this->m_current_env;
	}

	Environment * langXState::getGlobalEnv() const
	{
		return this->m_global_env;
	}

	Environment * langXState::getNearestObjectEnv() const
	{
		Environment *env = this->m_current_env;

		while (env != NULL)
		{
			if (env->isObjectEnvironment())
			{
				if (env->isEnvEnvironment())
				{
					return ((EnvironmentBridgeEnv*)env)->getBridgeEnv();
				}
				return env;
			}

			env = env->getParent();
		}

		return nullptr;
	}

	Environment * langXState::getEnvironment(int deep)
	{
		if (this->m_current_deep < deep)
		{
			return nullptr;
		}

		if (this->m_current_deep == deep)
		{
			return this->m_current_env;
		}

		Environment *env = this->m_current_env->getParent();
		while (env != nullptr && env->getDeep() != deep)
		{
			env = env->getParent();
		}

		return env;
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

	Allocator & langXState::getAllocator() const
	{
		return (*this->m_allocator);
	}

	StackTrace & langXState::getStackTrace()
	{
		return this->m_stacktrace;
	}

	void langXState::printStackTrace() const
	{
		StrackTraceFrameArray array1 = this->m_stacktrace.frames();

		// 不打印自己这个函数
		for (int i = array1.length - 2; i >= 0; i--)
		{
			printf("%s\n", array1.frame[i]->getInfo());
		}

		free(array1.frame);
	}

	void langXState::throwException(langXObjectRef *obj)
	{
		// 丢出一个异常

		// 找到try环境
		TryEnvironment *tryEnv = NULL;
		Environment *env = this->m_current_env;
		while (1)
		{
			if (env == NULL)
			{
				break;
			}

			if (env->isTryEnvironment())
			{
				if (env->isEnvEnvironment())
				{
					tryEnv = (TryEnvironment *)((EnvironmentBridgeEnv*)env)->getBridgeEnv();
				}
				else {
					tryEnv = (TryEnvironment *)env;
				}
				break;
			}

			// 因为丢出了异常， 所以到 try 环境之前的所有环境都会变成死亡环境
			//env->setDead(true);
			Environment *p = env->getParent();

			// 退回一级环境 ，直到退回try 环境
			backEnv();

			env = p;
		}

		if (tryEnv == NULL)
		{
			printf("cannot find try env, throw error!\n");
			return;
		}

		//  退出try 环境
		backEnv(false);

		// check call back first.
		CBCatch c = tryEnv->getCatchCB();
		if (c != NULL)
		{
			c(obj);

			// 新建一个环境，并设置当前环境为 dead 环境
			newEnv();
			this->m_current_env->setDead(true);

			// 删除对象
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}
		else {
			setInException(true);
			// 将异常赋值
			// 进入catch 环境
			env = newEnv();
			Node *cNode = tryEnv->getCatchNode();
			env->putObject(cNode->opr_obj->op[0]->var_obj->name, obj);

			// 执行 catch 块的语句
			__execNode(cNode->opr_obj->op[1]);

			// 将环境back 到env
			while (env != this->m_current_env)
			{
				if (this->m_current_env == NULL)
				{
					break;
				}

				backEnv();
			}

			// 主动进行 try-catch 操作的时候 ， try 执行后会释放一个环境，所以当前环境保留
			// 将当前环境设置为死亡环境， 这样就可以忽略 try 内的剩余操作了？
			env->setDead(true);

			setInException(false);

			// 删除对象
			delete obj->getRefObject();
			delete obj;
			obj = NULL;
		}

		// 销毁try 环境
		delete tryEnv;
		tryEnv = NULL;
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

		//  释放内存到 深度为1 的 环境
		backToDeep1Env();

		this->m_script_env = new XNameSpaceEnvironment(s);
		this->m_current_deep++;
		this->m_script_env->setDeep(this->m_current_deep);
		this->m_script_env->setParent(this->m_current_env);
		this->m_current_env = this->m_script_env;
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

		//  释放内存到 深度为1 的 环境
		backToDeep1Env();

		this->m_script_env = env;
		this->m_current_deep++;
		this->m_script_env->setDeep(this->m_current_deep);
		this->m_script_env->setParent(this->m_current_env);
		this->m_current_env = this->m_script_env;

	}

	int langXState::doFile(const char *filename)
	{
		if (filename == NULL)
		{
			return -1;
		}

		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			throwException(newFileNotFoundException(filename)->addRef());
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

		if (this->m_script_env_map.find(tmp) == this->m_script_env_map.end())
		{
			ScriptEnvironment * env = new ScriptEnvironment(tmp);
			this->m_script_env_map[tmp] = env;
			newScriptEnv(env);
		}
		else {
			newScriptEnv(this->m_script_env_map.at(tmp));
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

	int langXState::requireFile(const char *filename)
	{

		if (filename == NULL)
		{
			return -1;
		}

		FILE *fp = fopen(filename, "r");
		if (fp == NULL)
		{
			throwException(newFileNotFoundException(filename)->addRef());
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

		//printf("file %s eof!\n", m_parsing_file);
		free(this->m_parsing_file);
		this->m_parsing_file = NULL;

		if (this->m_doing_files.empty())
		{
			return;
		}


		char * p = this->m_doing_files.front();
		this->m_doing_files.erase(this->m_doing_files.begin());
		this->m_parsing_file = p;

		int index = 0;
		while (this->m_script_env_map.find(p) == this->m_script_env_map.end())
		{
			//  脚本空间无法找到该变量 ，继续向下搜索
			if (index >= this->m_doing_files.size())
			{
				return;
			}

			auto tmpIt = this->m_doing_files.begin();
			advance(tmpIt, index);
			p = (*tmpIt);

			index++;
		}

		//printf("change file to %s. change script env to file: %s \n", m_parsing_file , p );
		newScriptEnv(this->m_script_env_map[p]);
	}

	int langXState::loadModule(const char * path)
	{
#ifdef WIN32
		// WIN32实现
		return -1;
#else
		void *soObj = dlopen(path, RTLD_LAZY);
		if (soObj == NULL) {
			printf("dlopen err:%s.\n", dlerror());
			return -1;
		}

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

		// TODO  等待 langX 卸载的时候 在卸载动态库
		//dlclose(soObj);

		return ret;
#endif

	}


	void langXState::backToDeep1Env()
	{
		if (this->m_current_deep <= 1)
		{
			return;
		}

		while (this->m_current_deep != 2) {
			backEnv();
		}

		if (this->m_current_env->getType() == TScriptEnvironment)
		{
			backEnv(false);
		}
		else {
			backEnv();
		}
	}

}