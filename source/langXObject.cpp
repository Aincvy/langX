#include <string>
#include <iostream>
#include <string.h>
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Function.h"
#include "../include/NodeCreator.h"
#include "../include/Allocator.h"
#include "../include/langXObject.h"
#include "../include/langXObjectRef.h"
#include "../include/Environment.h"
#include "../include/Utils.h"
#include "../include/langXThread.h"

namespace langX {

	langXObject::langXObject(ClassInfo *claxxInfo)
	{
		// 先生成父类对象
		ClassInfo *pclass = claxxInfo->getParent();
		if (pclass != nullptr)
		{
			this->m_parent = pclass->newObject(false);
		}

		this->m_class_info = claxxInfo;
		this->m_my_env = new ObjectBridgeEnv(this);
		this->m_my_env->setParent(NULL);

		std::map<std::string, Object*> & map = claxxInfo->getMembers();
		for (auto i = map.begin(); i != map.end(); i++)
		{
			// printf("%s: %d\n", i->first.c_str(), i->second->getType());

			Object *obj = i->second->clone(true);
			//  类的字段值 为对象专有， 产生环境也是对象的环境
			obj->setEmergeEnv(this->m_my_env);
			obj->setName(i->first);
			obj->regenCharacteristic();     // 重新生成特征字符串 ，当前对象和类中的元素是不一样的。
			this->m_members[i->first] = obj;
		}

		char t[100];
		randomCharacteristic(t, 100, this, 8);
		this->m_characteristic = std::string(t);
	}

	langXObject::~langXObject()
	{
		//std::cout << "langXObject::~langXObject() " << this->m_class_info->getName() << std::endl;

		this->m_disposing = true;
		// 先干掉自己， 再干掉父类对象

		// 先调用自己的 析构函数
		std::string str = "~";
		str += this->m_class_info->getName();
		callFunction(str.c_str());

		if (this->m_my_env != NULL)
		{
			delete this->m_my_env;
			this->m_my_env = NULL;
		}

		// 清理引用
		for (auto i = 0; i < this->m_refs.size(); i++)
		{
			langXObjectRef *r = this->m_refs.at(i);
			if (!r)
			{
				continue;
			}

			r->setRefObject(nullptr);
		}
		this->m_refs.clear();

		// 干掉父类对象
		if (this->m_parent != NULL)
		{
			delete this->m_parent;
			this->m_parent = NULL;
		}
	}

	bool langXObject::typeCheck(const char *name) const {
		return m_class_info->isInstanceOf(name);
	}

	void langXObject::setMember(const char *name, Object *obj)
	{
		setMember(name, obj, false);
	}

	void langXObject::setMember(const char *name, Object *obj, bool flag)
	{
		if (name == nullptr)
		{
			return;
		}

		if (this->m_members.find(name) == this->m_members.end())
		{
			if (this->m_parent == NULL)
			{
				printf("cannot find member %s!\n", name);
				return;
			}

			this->m_parent->setMember(name, obj, true);
			return;
		}

		Object *a = this->m_members[name];
		if (a->getType() == obj->getType())
		{
			a->update(obj);
		}
		else {
			Allocator::free(a);
			a = NULL;
			a = obj->clone();
			a->setName(name);
			this->m_members.find(name)->second = a;
		}
	}

	bool langXObject::hasMember(const char *name) const
	{
		if (this->m_members.find(name) == this->m_members.end())
		{
			if (this->m_parent == NULL)
			{
				return false;
			}

			return this->m_parent->hasMember(name);
		}
		return true;
	}

	Object * langXObject::getMember(const char *name) const
	{
		return getMember(name, false);
	}

	Object * langXObject::getMember(const char *name, bool flag) const
	{
		if (this->m_members.find(name) != this->m_members.end())
		{
			return this->m_members.at(name);
		}

		if (this->m_parent != NULL)
		{
			return this->m_parent->getMember(name, true);
		}

		return NULL;
	}

	const std::map<std::string, Object*> & langXObject::getMemberMap() const {
		return this->m_members;
	}

	Function * langXObject::getFunction(const char *name) const
	{
		return getFunction(name, false);
	}

	Function * langXObject::getFunction(const char *name, bool flag) const
	{
		return this->m_class_info->getFunction(name, flag);
	}

	const ClassInfo * langXObject::getClassInfo() const
	{
		return this->m_class_info;
	}

	const char * langXObject::getClassName() const
	{
		return this->m_class_info->getName();
	}

	void langXObject::justAddRef(langXObjectRef *r)
	{
		this->m_ref_count++;
		if (r)
		{
			r->setCharacteristic(this->m_characteristic.c_str());
			this->m_refs.push_back(r);
		}
		this->m_zero_ref_time = 0;
	}

	langXObjectRef * langXObject::addRef()
	{
		this->m_ref_count++;
		langXObjectRef *r = new langXObjectRef(this);
		r->setCharacteristic(this->m_characteristic.c_str());
		this->m_refs.push_back(r);
		this->m_zero_ref_time = 0;
		return r;
	}

	void langXObject::subRef()
	{
		if (-- this->m_ref_count <= 0)
		{
			this->m_zero_ref_time = getTime();
		}
		this->m_ref_count--;
	}

	void langXObject::subRef(langXObjectRef *r)
	{
		if (!r)
		{
			return;
		}

		//r->setCharacteristic("no_pointer_to_anything");
		for (auto i = m_refs.begin(); i != m_refs.end(); i++)
		{
			if ((*i) == r)
			{
				m_refs.erase(i++);
				break;
			}
		}
		subRef();

		//printf("void langXObject::subRef(langXObjectRef *r) \n");
	}

	int langXObject::getRefCount() const
	{
		return this->m_ref_count;
	}

	Function * langXObject::getConstructor() const
	{
		return getFunction(this->m_class_info->getName());
	}

	void langXObject::callConstructor(ArgsList *args, const char *remark, langXThread *thread)
	{
		Function *func = getConstructor();
		if (func)
		{

            thread->getStackTrace().newFrame(this->m_class_info, func, "<__init>");
			Environment *env = getObjectEnvironment();
            thread->newEnvByBridge(env);
			callFunc(func, args, remark );
			thread->getStackTrace().popFrame();
			thread->backEnv();

		}
	}

	void langXObject::callConstructor(ArgsList *args, const char *remark)
	{
		// 强行执行构造函数
		Function *func = getConstructor();
		if (func)
		{
			langXThread *thread = getState()->curThread();

			// 运算函数
            thread->getStackTrace().newFrame(this->m_class_info, func, "<__init>");
			Environment *env = getObjectEnvironment();
            thread->newEnvByBridge(env);
			callFunc(func, args, remark);
			thread->getStackTrace().popFrame();
			thread->backEnv();

		}
	}

	Object * langXObject::callFunction(const char *name) const
	{
		Function * func = getFunction(name);
		if (func == NULL)
		{
			return NULL;
		}

        getState()->curThread()->newEnvByBridge(this->m_my_env);
		Object *obj = func->call();
		getState()->curThread()->backEnv();

		return obj;
	}

	Object * langXObject::callFunction(const char *name, Object* args[], int len, const char * remark)
	{
		Function * func = getFunction(name);
		if (func == NULL)
		{
			return NULL;
		}

		FunctionRef fRef(func);
		Object *ret = fRef.call(args, len, remark);

		return ret;
	}

	void langXObject::setMembersEmergeEnv(Environment *env)
	{
		for (auto i = this->m_members.begin(); i != this->m_members.end(); i++)
		{
			i->second->setEmergeEnv(env);
		}
	}

	Environment * langXObject::getObjectEnvironment() const
	{
		return this->m_my_env;
	}

	long langXObject::getZeroRefTime() const
	{
		return this->m_zero_ref_time;
	}

	void langXObject::set3rdObj(void *p)
	{
		this->m_3rdObj = p;
	}

	void * langXObject::get3rdObj() const
	{
		return this->m_3rdObj;
	}

	const char * langXObject::characteristic() const
	{
		return this->m_characteristic.c_str();
	}

	bool langXObject::isDisposing() const
	{
		return this->m_disposing;
	}

	langXObjectExtend::langXObjectExtend(ClassInfo *c) : langXObject(c)
	{

	}

	langXObjectExtend::~langXObjectExtend()
	{

	}

	void langXObjectExtend::addFunction(const char *name, Function *f)
	{
		this->m_function_map[name] = f;
	}

	Function * langXObjectExtend::getFunction(const char *name) const
	{
		auto it = this->m_function_map.find(name);
		if (it == this->m_function_map.end())
		{
			return nullptr;
		}
		return it->second;
	}

	void langXObjectExtend::addMember(const char *name, Object *v)
	{
		if (name == nullptr)
		{
			return;
		}

		auto it = this->m_members.find(name);


		if (it == this->m_members.end())
		{
			this->m_members[name] = Allocator::allocateNull();
		}

		setMember(name, v);
	}
}
