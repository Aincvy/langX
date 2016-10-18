#include <stdio.h>
#include <algorithm>
#include "../include/Environment.h"
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Number.h"
#include "../include/Function.h"
#include "../include/langXObject.h"
#include "../include/XNameSpace.h"
#include "../include/YLlangX.h"
#include "../include/Exception.h"
#include "../include/Allocator.h"

namespace langX {



	Environment::Environment()
	{
		this->m_parent = NULL;
	}

	Environment::~Environment()
	{

	}

	void Environment::putFunction(const char *name, Function *obj)
	{
		//putFunction(std::string(name), obj);
	}

	void Environment::putFunction(const std::string &name, Function *obj)
	{
		//this->m_functions_map[name] = obj;
	}

	Function * Environment::getFunction(const std::string &name)
	{
		if (this->m_parent != NULL)
		{
			return this->m_parent->getFunction(name);
		}
		return NULL;
	}

	Function * Environment::getFunctionSelf(const std::string &)
	{
		return nullptr;
	}

	void Environment::putClass(const char *name, ClassInfo *claxx)
	{
		char tmp[200] = { 0 };
		sprintf(tmp, "cannot put class %s into a (Environment/TryEnvironment)!", name);
		getState()->throwException(newUnsupportedOperationException(tmp)->addRef());

		delete claxx;
	}

	ClassInfo * Environment::getClass(const char *name)
	{
		if (this->m_parent != NULL)
		{
			return this->m_parent->getClass(name);
		}
		return nullptr;
	}

	ClassInfo * Environment::getClassSelf(const char *)
	{
		return nullptr;
	}

	Environment * Environment::getParent() const
	{
		return this->m_parent;
	}

	void Environment::setParent(Environment *env)
	{
		this->m_parent = env;
	}

	void Environment::setDead(bool b)
	{
		this->m_dead = b;
	}

	bool Environment::isDead() const
	{
		return this->m_dead;
	}

	void Environment::setRestrict(bool flag)
	{
		this->m_restrict = flag;
	}

	bool Environment::isRestrict() const
	{
		return this->m_restrict;
	}

	bool Environment::isClassEnvironment() const
	{
		return false;
	}

	bool Environment::isObjectEnvironment() const
	{
		return false;
	}

	bool Environment::isTryEnvironment() const
	{
		return false;
	}

	bool Environment::isEnvEnvironment() const
	{
		return false;
	}

	bool Environment::isNameSpaceEnv() const
	{
		return false;
	}

	int Environment::getDeep() const
	{
		return this->m_deep;
	}

	void Environment::setDeep(int i)
	{
		this->m_deep = i;
	}





	ClassBridgeEnv::ClassBridgeEnv(ClassInfo *claxx)
	{
		this->m_class = claxx;
	}

	ClassBridgeEnv::~ClassBridgeEnv()
	{
	}

	void ClassBridgeEnv::putObject(const char *name, Object *obj)
	{
		if (this->m_class == NULL)
		{
			return;
		}
		this->m_class->addMember(name, obj);
	}

	void ClassBridgeEnv::putObject(const std::string &name, Object *obj)
	{
		if (this->m_class == NULL)
		{
			return;
		}
		this->m_class->addMember(name.c_str(), obj);
	}

	Object * ClassBridgeEnv::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n" ,this );

		Object *obj = NULL;
		if (this->m_class != NULL)
		{
			obj = this->m_class->getMember(name.c_str());
		}

		if (obj == NULL)
		{
			if (!this->m_restrict && this->m_parent != NULL)
			{
				return this->m_parent->getObject(name);
			}
		}

		return obj;
	}

	Object * ClassBridgeEnv::getObjectSelf(const char *) const
	{
		return nullptr;
	}

	void ClassBridgeEnv::putFunction(const char *name, Function *func)
	{
		if (this->m_class == NULL)
		{
			return;
		}
		this->m_class->addFunction(name, func);
	}

	void ClassBridgeEnv::putFunction(const std::string &name, Function *func)
	{
		if (this->m_class == NULL)
		{
			return;
		}
		this->m_class->addFunction(name.c_str(), func);
	}

	Function * ClassBridgeEnv::getFunction(const std::string &name)
	{
		if (this->m_class == NULL)
		{
			if (this->m_parent != nullptr)
			{
				return this->m_parent->getFunction(name);
			}

			return NULL;
		}
		return this->m_class->getFunction(name.c_str());
	}

	Function * ClassBridgeEnv::getFunctionSelf(const std::string &name)
	{
		return this->m_class->getFunction(name.c_str());
	}

	bool ClassBridgeEnv::isClassEnvironment() const
	{
		return true;
	}

	EnvironmentType ClassBridgeEnv::getType() const
	{
		return EnvironmentType::TClassBridgeEnv;
	}



	ObjectBridgeEnv::ObjectBridgeEnv(langXObject *obj)
	{
		this->m_object = obj;
	}

	ObjectBridgeEnv::~ObjectBridgeEnv()
	{
	}

	void ObjectBridgeEnv::putObject(const char *name, Object *obj)
	{
		if (this->m_object == NULL)
		{
			return;
		}
		this->m_object->setMember(name, obj);
	}

	void ObjectBridgeEnv::putObject(const std::string &name, Object *obj)
	{
		if (this->m_object == NULL)
		{
			return;
		}
		this->m_object->setMember(name.c_str(), obj);
	}

	Object * ObjectBridgeEnv::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n", this);
		if (this->m_object == NULL)
		{
			if (this->m_parent != NULL && !m_restrict)
			{
				return this->m_parent->getObject(name);
			}
		}
		Object * r = this->m_object->getMember(name.c_str());
		if (r == NULL)
		{
			if (this->m_parent != NULL && !m_restrict)
			{
				return this->m_parent->getObject(name);
			}
		}
		return r;
	}

	Object * ObjectBridgeEnv::getObjectSelf(const char *name) const
	{
		if (this->m_object != NULL)
		{
			return this->m_object->getMember(name);
		}
		return nullptr;
	}

	void ObjectBridgeEnv::putFunction(const char *name, Function *f)
	{
		char tmp[200] = { 0 };
		sprintf(tmp,"cannot put function %s into a object!", name);
		getState()->throwException(newUnsupportedOperationException(tmp)->addRef());

		delete f;
	}

	void ObjectBridgeEnv::putFunction(const std::string &name, Function *f)
	{
		char tmp[200] = { 0 };
		sprintf(tmp, "cannot put function %s into a object!", name.c_str());
		getState()->throwException(newUnsupportedOperationException(tmp)->addRef());

		delete f;
	}

	Function * ObjectBridgeEnv::getFunction(const std::string &name)
	{
		if (this->m_object == NULL)
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getFunction(name);
			}
		}
		Function * func = this->m_object->getFunction(name.c_str());
		if (func == NULL)
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getFunction(name);
			}
		}
		return func;
	}

	Function * ObjectBridgeEnv::getFunctionSelf(const std::string &name)
	{
		if (this->m_object == NULL)
		{
			return NULL;
		}

		return this->m_object->getFunction(name.c_str());
	}

	langXObject * ObjectBridgeEnv::getEnvObject() const
	{
		return this->m_object;
	}

	bool ObjectBridgeEnv::isObjectEnvironment() const
	{
		return true;
	}

	EnvironmentType ObjectBridgeEnv::getType() const
	{
		return EnvironmentType::TObjectBridgeEnv;
	}

	TryEnvironment::TryEnvironment()
	{
	}

	TryEnvironment::~TryEnvironment()
	{
		Allocator& allocator = getState()->getAllocator();
		this->m_parent = NULL;
		//printf("~Environment\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				//a->second->decRefCount();
				allocator.free(a->second);
			}

			m_objects_map.clear();
		}

		if (!m_functions_map.empty())
		{
			for (auto a = m_functions_map.begin(); a != m_functions_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_functions_map.clear();
		}

	}

	bool TryEnvironment::isTryEnvironment() const
	{
		return true;
	}

	void TryEnvironment::setCatchCB(CBCatch c)
	{
		this->m_catch_cb = c;
	}

	CBCatch TryEnvironment::getCatchCB() const
	{
		return (this->m_catch_cb);
	}

	void TryEnvironment::setCatchNode(Node *n)
	{
		this->m_catch_node = n;
	}

	Node * TryEnvironment::getCatchNode() const
	{
		return this->m_catch_node;
	}

	void TryEnvironment::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name),obj);
	}

	void TryEnvironment::putObject(const std::string &name, Object *obj)
	{
		this->m_objects_map[name] = obj;
	}

	Object * TryEnvironment::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n", this);

		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			if (this->m_parent != nullptr)
			{
				return this->m_parent->getObject(name);
			}
			return NULL;
		}

		return this->m_objects_map.at(name);
	}

	Object * TryEnvironment::getObjectSelf(const char *name) const
	{
		if (this->m_parent != nullptr)
		{
			return this->m_parent->getObjectSelf(name);
		}
	}

	void TryEnvironment::putFunction(const char *name, Function *f)
	{
		putFunction(std::string(name), f);
	}

	void TryEnvironment::putFunction(const std::string &name, Function *f)
	{
		this->m_functions_map[name] = f;
	}

	Function * TryEnvironment::getFunction(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			// not found.
			if (this->m_parent != nullptr)
			{
				return this->m_parent->getFunction(name);
			}

			return NULL;
		}
		return this->m_functions_map.at(name);
	}

	Function * TryEnvironment::getFunctionSelf(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			// not found.

			return NULL;
		}
		return this->m_functions_map.at(name);
	}

	EnvironmentType TryEnvironment::getType() const
	{
		return EnvironmentType::TTryEnvironment;
	}

	EnvironmentBridgeEnv::EnvironmentBridgeEnv(Environment *env)
	{
		this->m_env = env;
	}

	EnvironmentBridgeEnv::~EnvironmentBridgeEnv()
	{
	}

	void EnvironmentBridgeEnv::putObject(const char *name, Object *obj)
	{
		this->m_env->putObject(name, obj);
	}

	void EnvironmentBridgeEnv::putObject(const std::string &name, Object *obj)
	{
		this->m_env->putObject(name, obj);
	}

	Object * EnvironmentBridgeEnv::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n", this);

		Object *o = this->m_env->getObject(name);
		if (o == NULL)
		{
			if (this->getParent() != NULL)
			{
				return this->getParent()->getObject(name);
			}
		}
		return o;
	}

	Object * EnvironmentBridgeEnv::getObjectSelf(const char *name) const
	{
		return this->m_env->getObjectSelf(name);
	}

	void EnvironmentBridgeEnv::putFunction(const char *name, Function *f)
	{
		this->m_env->putFunction(name, f);
	}

	void EnvironmentBridgeEnv::putFunction(const std::string &name, Function *f)
	{
		this->m_env->putFunction(name, f);
	}

	Function * EnvironmentBridgeEnv::getFunction(const std::string &name)
	{
		Function *f = this->m_env->getFunction(name);
		if (f == NULL)
		{
			if (this->getParent() != NULL)
			{
				return this->getParent()->getFunction(name);
			}
		}
		return f;
	}

	Function * EnvironmentBridgeEnv::getFunctionSelf(const std::string &name)
	{
		return this->m_env->getFunctionSelf(name);
	}

	void EnvironmentBridgeEnv::putClass(const char *name, ClassInfo *c)
	{
		this->m_env->putClass(name, c);
	}

	ClassInfo * EnvironmentBridgeEnv::getClass(const char *name)
	{
		return this->m_env->getClass(name);
	}

	ClassInfo * EnvironmentBridgeEnv::getClassSelf(const char *name)
	{
		return this->m_env->getClassSelf(name);
	}

	Environment * EnvironmentBridgeEnv::getBridgeEnv()
	{
		return this->m_env;
	}

	bool EnvironmentBridgeEnv::isEnvEnvironment() const
	{
		return true;
	}

	bool EnvironmentBridgeEnv::isClassEnvironment() const
	{
		return this->m_env->isClassEnvironment();
	}

	bool EnvironmentBridgeEnv::isObjectEnvironment() const
	{
		return this->m_env->isObjectEnvironment();
	}

	bool EnvironmentBridgeEnv::isTryEnvironment() const
	{
		return this->m_env->isTryEnvironment();
	}

	bool EnvironmentBridgeEnv::isNameSpaceEnv() const
	{
		return this->m_env->isNameSpaceEnv();
	}

	EnvironmentType EnvironmentBridgeEnv::getType() const
	{
		return EnvironmentType::TEnvironmentBridgeEnv;
	}

	DefaultEnvironment::DefaultEnvironment()
	{
	}

	DefaultEnvironment::~DefaultEnvironment()
	{
		Allocator& allocator = getState()->getAllocator();
		this->m_parent = NULL;
		//printf("~Environment\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				//a->second->decRefCount();
				//delete a->second;
				allocator.free(a->second);
			}

			m_objects_map.clear();
		}
	}

	void DefaultEnvironment::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name), obj);
	}

	void DefaultEnvironment::putObject(const std::string &name, Object *obj)
	{
		this->m_objects_map[name] = obj;
	}

	Object * DefaultEnvironment::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n", this);

		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			if (this->m_parent != NULL && !m_restrict)
			{
				return this->m_parent->getObject(name);
			}
			return NULL;
		}

		return this->m_objects_map[name];
	}

	Object * DefaultEnvironment::getObjectSelf(const char *name) const
	{
		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			return NULL;
		}

		return this->m_objects_map.at(name);
	}

	void DefaultEnvironment::putFunction(const char *, Function *)
	{

	}

	void DefaultEnvironment::putFunction(const std::string &, Function *)
	{

	}

	Function * DefaultEnvironment::getFunction(const std::string & name)
	{
		if (this->m_parent != NULL)
		{
			return this->m_parent->getFunction(name);
		}
		return nullptr;
	}

	EnvironmentType DefaultEnvironment::getType() const
	{
		return EnvironmentType::TDefaultEnvironment;
	}

	XNameSpaceEnvironment::XNameSpaceEnvironment(XNameSpace *space)
	{
		this->m_space = space;
	}

	XNameSpaceEnvironment::~XNameSpaceEnvironment()
	{

	}

	const char * XNameSpaceEnvironment::getName() const
	{
		return this->m_space->getName();
	}


	void XNameSpaceEnvironment::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name), obj);
	}

	void XNameSpaceEnvironment::putObject(const std::string &name, Object *obj)
	{
		this->m_space->putObject(name, obj);
	}

	Object * XNameSpaceEnvironment::getObject(const std::string &name)
	{
		//printf("getObject on env-p: %p\n", this);

		return this->m_space->getObject(name);
	}

	Object * XNameSpaceEnvironment::getObjectSelf(const char *name) const
	{
		return this->m_space->getObjectSelf(name);
	}

	void XNameSpaceEnvironment::putFunction(const char *name, Function *obj)
	{
		putFunction(std::string(name), obj);
	}

	void XNameSpaceEnvironment::putFunction(const std::string &name, Function *obj)
	{
		this->m_space->putFunction(name, obj);
	}

	Function * XNameSpaceEnvironment::getFunction(const std::string &name)
	{
		Function * f = this->m_space->getFunction(name);
		if (f == NULL)
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getFunction(name);
			}
		}
		return f;
	}

	void XNameSpaceEnvironment::putClass(const char *name, ClassInfo *claxx)
	{
		this->m_space->putClass(name, claxx);
	}

	ClassInfo * XNameSpaceEnvironment::getClass(const char *name)
	{
		ClassInfo *c = this->m_space->getClass(name);
		if (c == NULL)
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getClass(name);
			}
		}
		return c;
	}

	ClassInfo * XNameSpaceEnvironment::getClassSelf(const char *name)
	{
		return  this->m_space->getClass(name);
	}

	void XNameSpaceEnvironment::putNameSpace(const char *name, XNameSpace *env)
	{
		this->m_space->putNameSpace(name, env);
	}

	XNameSpace * XNameSpaceEnvironment::getNameSpace(const char *name)
	{
		return this->m_space->getNameSpace(name);
	}

	void XNameSpaceEnvironment::setXNameSpace(XNameSpace *s)
	{
		this->m_space = s;
	}

	EnvironmentType XNameSpaceEnvironment::getType() const
	{
		return EnvironmentType::TXNameSpaceEnvironment;
	}

	GlobalEnvironment::GlobalEnvironment()
	{
		//  公共环境 ， 算为死亡环境
		setDead(true);
	}

	GlobalEnvironment::~GlobalEnvironment()
	{
		// 释放函数信息和类信息
		if (!m_functions_map.empty())
		{
			for (auto a = m_functions_map.begin(); a != m_functions_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_functions_map.clear();
		}

		if (!m_classes_map.empty())
		{
			for (auto a = m_classes_map.begin(); a != m_classes_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_classes_map.clear();
		}

	}

	void GlobalEnvironment::putObject(const char *, Object *)
	{
	}

	void GlobalEnvironment::putObject(const std::string &, Object *)
	{
	}

	Object * GlobalEnvironment::getObject(const std::string &)
	{
		//printf("getObject on GlobalEnvironment env-p: %p\n", this);

		return nullptr;
	}

	Object * GlobalEnvironment::getObjectSelf(const char *) const
	{
		return nullptr;
	}

	void GlobalEnvironment::putFunction(const char *name, Function *obj)
	{
		putFunction(std::string(name), obj);
	}

	void GlobalEnvironment::putFunction(const std::string &name, Function *obj)
	{
		this->m_functions_map[name] = obj;
	}

	Function * GlobalEnvironment::getFunction(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getFunction(name);
			}
			return NULL;
		}
		return this->m_functions_map[name];
	}

	Function * GlobalEnvironment::getFunctionSelf(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			// not found.

			return NULL;
		}
		return this->m_functions_map.at(name);
	}

	void GlobalEnvironment::putClass(const char *name, ClassInfo *claxx)
	{
		if (claxx == NULL)
		{
			return;
		}
		this->m_classes_map[name] = claxx;
	}

	ClassInfo * GlobalEnvironment::getClass(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			if (this->m_parent != NULL)
			{
				return this->m_parent->getClass(name);
			}
			return nullptr;
		}
		return this->m_classes_map.at(name);
	}

	ClassInfo * GlobalEnvironment::getClassSelf(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			return nullptr;
		}
		return this->m_classes_map.at(name);
	}

	EnvironmentType GlobalEnvironment::getType() const
	{
		return EnvironmentType::TGlobalEnvironment;
	}

	ScriptEnvironment::ScriptEnvironment(const char *name)
	{
		this->m_name = std::string(name);
	}

	ScriptEnvironment::~ScriptEnvironment()
	{
		Allocator &allocator = getState()->getAllocator();
		// 释放内存
		this->m_parent = NULL;
		//printf("~Environment\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				//a->second->decRefCount();
				//delete a->second;
				allocator.free(a->second);
			}

			m_objects_map.clear();
		}

		if (!m_functions_map.empty())
		{
			for (auto a = m_functions_map.begin(); a != m_functions_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_functions_map.clear();
		}

		if (!m_classes_map.empty())
		{
			for (auto a = m_classes_map.begin(); a != m_classes_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_classes_map.clear();
		}
	}

	void ScriptEnvironment::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name), obj);
	}

	void ScriptEnvironment::putObject(const std::string &name, Object *obj)
	{
		this->m_objects_map[name] = obj;
	}

	Object * ScriptEnvironment::getObject(const std::string &name)
	{
		//printf("getObject on ScriptEnvironment env-p: %p\n", this);

		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			if (!this->m_namespaces.empty())
			{
				for (auto i = this->m_namespaces.begin(); i != this->m_namespaces.end(); i++)
				{
					Object *f = (*i)->getObject(name);
					if (f != nullptr)
					{
						return f;
					}
				}
			}

			if (this->m_parent != NULL && !m_restrict)
			{
				return this->m_parent->getObject(name);
			}
			return NULL;
		}

		return this->m_objects_map[name];
	}

	Object * ScriptEnvironment::getObjectSelf(const char *name) const
	{
		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			return NULL;
		}

		return this->m_objects_map.at(name);
	}

	void ScriptEnvironment::putFunction(const char *name, Function *obj)
	{
		putFunction(std::string(name), obj);
	}

	void ScriptEnvironment::putFunction(const std::string &name, Function *obj)
	{
		this->m_functions_map[name] = obj;
	}

	Function * ScriptEnvironment::getFunction(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			if (!this->m_namespaces.empty())
			{
				for (auto i = this->m_namespaces.begin(); i != this->m_namespaces.end(); i++)
				{
					Function *f = (*i)->getFunction(name);
					if (f != nullptr)
					{
						return f;
					}
				}
			}

			if (this->m_parent != NULL)
			{
				return this->m_parent->getFunction(name);
			}
			return NULL;
		}
		return this->m_functions_map[name];
	}

	Function * ScriptEnvironment::getFunctionSelf(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			// not found.

			return NULL;
		}
		return this->m_functions_map.at(name);
	}

	void ScriptEnvironment::putClass(const char *name, ClassInfo *claxx)
	{
		if (claxx == NULL)
		{
			return;
		}
		this->m_classes_map[name] = claxx;
	}

	ClassInfo * ScriptEnvironment::getClass(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			if (this->m_ref_classes_map.find(name) != this->m_ref_classes_map.end())
			{
				return this->m_ref_classes_map.at(name);
			}
			if (!this->m_namespaces.empty())
			{
				for (auto i = this->m_namespaces.begin(); i != this->m_namespaces.end(); i++)
				{
					ClassInfo *cInfo = (*i)->getClass(name);
					if (cInfo != nullptr)
					{
						return cInfo;
					}
				}
			}

			if (this->m_parent != NULL)
			{
				return this->m_parent->getClass(name);
			}
			return NULL;
		}
		return this->m_classes_map.at(name);
	}

	ClassInfo * ScriptEnvironment::getClassSelf(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			return nullptr;
		}
		return this->m_classes_map.at(name);
	}

	void ScriptEnvironment::addNameSpace(XNameSpace *s)
	{
		if (s == NULL)
		{
			return;
		}

		auto it = std::find(this->m_namespaces.begin(), this->m_namespaces.end(), s);
		if (it == this->m_namespaces.end())
		{
			this->m_namespaces.push_back(s);
		}
	}

	void ScriptEnvironment::addClassInfo(ClassInfo *c)
	{
		if (c == NULL)
		{
			return;
		}

		if (this->m_ref_classes_map.find(c->getName()) == this->m_ref_classes_map.end())
		{
			this->m_ref_classes_map[c->getName()] = c;
		}
	}

	const char * ScriptEnvironment::getName() const
	{
		return this->m_name.c_str();
	}

	EnvironmentType ScriptEnvironment::getType() const
	{
		return EnvironmentType::TScriptEnvironment;
	}

}