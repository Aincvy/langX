#include "../include/Environment.h"
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/Number.h"
#include "../include/Function.h"
#include "../include/langXObject.h"

namespace langX {



	Environment::Environment()
	{
		this->m_parent = NULL;
	}

	Environment::~Environment()
	{
		this->m_parent = NULL;
		//printf("~Environment\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_objects_map.clear();
		}
	}



	void Environment::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name), obj);		
	}

	void Environment::putObject(const std::string &name, Object *obj)
	{
		this->m_objects_map[name] = obj;
	}

	Object * Environment::getObject(const std::string &name)
	{

		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			if (this->m_parent != NULL && !m_restrict)
			{
				return this->m_parent->getObject(name);
			}
			return NULL;
		}

		Object * obj = this->m_objects_map[name];
		if (obj == NULL)
		{
			return NULL;
		}
		if (obj->getType() == NUMBER)
		{
			//printf("get a number object: %s\n", name.c_str());
			Number * number = (Number*)obj;
			//printf("getObject.. number value is: %.2f\n", number->getDoubleValue());
		}
		return obj;
	}

	void Environment::putFunction(const char *name, Function *obj)
	{
		putFunction(std::string(name), obj);
	}

	void Environment::putFunction(const std::string &name, Function *obj)
	{
		this->m_functions_map[name] = obj;
	}

	Function * Environment::getFunction(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			if (this->m_parent != NULL )
			{
				return this->m_parent->getFunction(name);
			}
			return NULL;
		}
		return this->m_functions_map[name];
	}

	void Environment::putClass(const char *name, ClassInfo *claxx)
	{
		if (claxx == NULL)
		{
			return;
		}
		this->m_classes_map[name] = claxx;
	}

	ClassInfo * Environment::getClass(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			return NULL;
		}
		return this->m_classes_map.at(name);
	}

	Environment * Environment::getParent() const
	{
		return this->m_parent;
	}

	void Environment::setParent(Environment *env)
	{
		this->m_parent = env;
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
			Environment::putObject(name,obj);
			return;
		}
		this->m_class->addMember(name, obj);
	}

	void ClassBridgeEnv::putObject(const std::string &name, Object *obj)
	{
		if (this->m_class == NULL)
		{
			Environment::putObject(name, obj);
			return;
		}
		this->m_class->addMember(name.c_str(), obj);
	}

	Object * ClassBridgeEnv::getObject(const std::string &name)
	{
		if (this->m_class == NULL)
		{
			return Environment::getObject(name);
		}
		return this->m_class->getMember(name.c_str());
	}

	void ClassBridgeEnv::putFunction(const char *name, Function *func)
	{
		if (this->m_class == NULL)
		{
			Environment::putFunction(name, func);
			return;
		}
		this->m_class->addFunction(name, func);
	}

	void ClassBridgeEnv::putFunction(const std::string &name, Function *func)
	{
		if (this->m_class == NULL)
		{
			Environment::putFunction(name, func);
			return;
		}
		this->m_class->addFunction(name.c_str(), func);
	}

	Function * ClassBridgeEnv::getFunction(const std::string &name)
	{
		if (this->m_class == NULL)
		{
			return Environment::getFunction(name);
		}
		return this->m_class->getFunction(name.c_str());
	}

	bool ClassBridgeEnv::isClassEnvironment() const
	{
		return true;
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
			Environment::putObject(name, obj);
			return;
		}
		this->m_object->setMember(name, obj);
	}

	void ObjectBridgeEnv::putObject(const std::string &name, Object *obj)
	{
		if (this->m_object == NULL)
		{
			Environment::putObject(name, obj);
			return;
		}
		this->m_object->setMember(name.c_str(), obj);
	}

	Object * ObjectBridgeEnv::getObject(const std::string &name)
	{
		if (this->m_object == NULL)
		{
			return Environment::getObject(name);
		}
		return this->m_object->getMember(name.c_str());
	}

	Function * ObjectBridgeEnv::getFunction(const std::string &name)
	{
		if (this->m_object == NULL)
		{
			return Environment::getFunction(name);
		}
		Function * func = this->m_object->getFunction(name.c_str());
		if (func == NULL)
		{
			return Environment::getFunction(name);
		}
		return func;
	}

	langXObject * ObjectBridgeEnv::getEnvObject() const
	{
		return this->m_object;
	}

	bool ObjectBridgeEnv::isObjectEnvironment() const
	{
		return true;
	}

}