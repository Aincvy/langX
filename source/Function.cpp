#include <stdlib.h>
#include "../include/Function.h"
#include "../include/ExecNode.h"

namespace langX {



	Function::Function()
	{

	}

	Function::Function(Node *root)
	{
		this->m_node_root = root;
	}

	Function::Function(char *name, Node *node)
	{
		this->m_name = name;
		this->m_node_root = node;
	}

	Function::~Function()
	{
		if (this->m_name != NULL)
		{
			free(this->m_name);
			this->m_name = NULL;
		}
	}

	const char * Function::getName() const
	{
		return this->m_name;
	}

	void Function::setName(char *name)
	{
		if (this->m_name != NULL)
		{
			free(this->m_name);
			this->m_name = NULL;
		}
		this->m_name = name;
	}

	void Function::setParamsList(ParamsList *list)
	{
		this->m_params_list = list;
	}

	ParamsList * Function::getParamsList()
	{
		return this->m_params_list;
	}

	int Function::getArgsCount() const
	{
		return 0;
	}

	Object * Function::call() const
	{
		if (m_node_root == nullptr)
		{
			return NULL;
		}

		__execNode(m_node_root);
		return m_node_root->value;
	}

	bool Function::isTrue() const
	{
		return true;
	}

	ObjectType Function::getType() const
	{
		return FUNCTION;
	}

	Object * Function::clone() const
	{
		return (Object*)this;
	}

	void Function::update(Object *)
	{
	}

	void Function::finalize()
	{
		delete this;
	}

}