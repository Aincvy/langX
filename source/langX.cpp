#include <stdio.h>
#include "../include/langX.h"
#include "../include/Number.h"

namespace langX {
	langXState::langXState()
	{
	}
	langXState::~langXState()
	{
		printf("~langXState\n");
		if (!m_objects_map.empty())
		{
			for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++) {
				delete (a->second);
			}
		}
	}
	void langXState::putObject(const char * name, Object *obj)
	{
		std::string str = std::string(name);
		auto a = this->m_objects_map.find(str);
		if (a != this->m_objects_map.end()) {
			Object * old_obj = a->second;
			if (old_obj->getType() == NUMBER && obj->getType() == NUMBER)
			{
				Number *n = (Number*)old_obj;
				n->update(((Number*)obj)->getDoubleValue());
				return;
			}

			delete a->second;
		}

		this->m_objects_map[str]= obj;
		if (obj->getType() == NUMBER)
		{
			//printf("putObject.. is Number,addr is: %p\n" , obj);
			Number * number = (Number*)obj;
			printf("putObject.. number %s value is: %.2f\n" ,name, number->getDoubleValue());
		}
	}

	void langXState::putObject(const std::string &name, Object *obj)
	{
		std::string str = std::string(name);
		this->m_objects_map[str] = obj;
	}
	Object * langXState::getObject(const std::string &name)
	{
		//printf("objects: %d\n" , m_objects_map.size());
		//for (auto a = m_objects_map.begin(); a != m_objects_map.end(); a++)
		//{
		//	printf("name: %s\n",a->first.c_str());
		//}
		//
		//printf("want to get value: %s\n", name.c_str());

		if (this->m_objects_map.find(name) == this->m_objects_map.end())
		{
			return NULL;
		}

		Object * obj = this->m_objects_map[name];
		if (obj->getType() == NUMBER)
		{
			printf("get a number object: %s\n",name.c_str());
			Number * number = (Number*)obj;
			printf("getObject.. number value is: %.2f\n", number->getDoubleValue());
		}
		return obj;
	}
}