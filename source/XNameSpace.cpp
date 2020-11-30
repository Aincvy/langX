#include "../include/XNameSpace.h"
#include "../include/Object.h"
#include "../include/ClassInfo.h"
#include "../include/langX.h"
#include "../include/NodeCreator.h"
#include "../include/Allocator.h"

namespace langX {
	XNameSpace::XNameSpace(const char *name)
	{
		this->m_name = std::string(name);
	}

	XNameSpace::~XNameSpace()
	{
		//printf("~XNameSpace\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				//a->second->decRefCount();
				delete a->second;
			}

			m_objects_map.clear();
		}
	}

	const char * XNameSpace::getName() const
	{
		return this->m_name.c_str();
	}

	void XNameSpace::putObject(const char *name, Object *obj)
	{
		putObject(std::string(name), obj);
	}

	void XNameSpace::putObject(const std::string &name, Object *obj)
	{
		if (obj) {
			obj = obj->clone();
		}
		else {
			obj = Allocator::allocate(NULLOBJECT);
		}

		obj->setName(name);
		this->m_objects_map[name] = obj;
	}

	Object * XNameSpace::getObject(const std::string &name)
	{
		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			// 寻找一下 引用的空间里面的对象
			for (auto it = this->m_ref_namespace_map.begin();  it != this->m_ref_namespace_map.end(); it++)
			{
				XNameSpace *ns = it->second;
				Object *t = ns->getObjectSelf(name.c_str());
				if (t != nullptr)
				{
					return t;
				}
			}

			return NULL;
		}

		return this->m_objects_map[name];
	}

	Object * XNameSpace::getObjectSelf(const char *name) const
	{
		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			return NULL;
		}

		return this->m_objects_map.at(name);
	}

	void XNameSpace::putFunction(const char *name, Function *obj)
	{
		putFunction(std::string(name), obj);
	}

	void XNameSpace::putFunction(const std::string &name, Function *obj)
	{
		this->m_functions_map[name] = obj;
	}

	Function * XNameSpace::getFunction(const std::string &name)
	{
		if (this->m_functions_map.find(name) == this->m_functions_map.end())
		{
			return NULL;
		}
		return this->m_functions_map[name];
	}

	void XNameSpace::putClass(ClassInfo * claxx)
	{
		if (!claxx)
		{
			return;
		}

		this->m_classes_map[claxx->getName()] = claxx;
	}

	void XNameSpace::putClass(const char *name, ClassInfo *claxx)
	{
		if (claxx == NULL)
		{
			return;
		}
		this->m_classes_map[name] = claxx;
	}

	ClassInfo * XNameSpace::getClass(const char *name)
	{
		if (this->m_classes_map.find(name) == this->m_classes_map.end())
		{
			return NULL;
		}
		return this->m_classes_map.at(name);
	}

	void XNameSpace::putNameSpace(const char *name, XNameSpace *env)
	{
		this->m_namespace_map[name] = env;
	}

	XNameSpace * XNameSpace::getNameSpace(const char *name)
	{
		if (this->m_namespace_map.find(name) == this->m_namespace_map.end())
		{
			return nullptr;
		}
		return this->m_namespace_map[name];
	}

	XNameSpace * XNameSpace::getNameSpaceWithCreate(const char *name)
	{
		if (this->m_namespace_map.find(name) != this->m_namespace_map.end())
		{
			return this->m_namespace_map[name];
		}

		auto space = new XNameSpace(name);
		this->m_namespace_map[name] = space;
		return space;
	}
	void XNameSpace::addRefNamespace(XNameSpace *ns)
	{
		if (ns == nullptr)
		{
			return;
		}

		const char *name =ns->getName();
		this->m_ref_namespace_map[name] = ns;
	}



}
