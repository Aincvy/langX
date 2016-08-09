#include <stdlib.h>
#include <string.h>
#include "../include/Function.h"
#include "../include/ExecNode.h"
#include "../include/langX.h"

namespace langX {

	extern Allocator m_exec_alloc;

	Function::Function()
	{

	}

	Function::Function(Node *root)
	{
		this->m_node_root = root;
	}

	Function::Function(const char *name, Node *node)
	{	
		setName(name);
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

	void Function::setName(const char *name)
	{
		if (this->m_name != NULL)
		{
			free(this->m_name);
			this->m_name = NULL;
		}
		this->m_name = strdup(name);
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

		m_node_root->state = IN_FUNC;
		__execNode(m_node_root);
		Object * obj = m_node_root->value->clone();
		m_exec_alloc.free(m_node_root->value);
		m_node_root->value = NULL;

		return obj;
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

	bool Function::is3rd() const
	{
		return false;
	}

	void Function::finalize()
	{
		delete this;
	}





	X3rdFunction::X3rdFunction()
	{
		m_worker = NULL;
		m_state = NULL;
	}

	X3rdFunction::~X3rdFunction()
	{
	}

	void X3rdFunction::setLangX(langXState *x)
	{
		this->m_state = x;
	}

	langXState * X3rdFunction::getLangX() const
	{
		return this->m_state;
	}

	void X3rdFunction::setWorker(X3rdFuncWorker worker)
	{
		this->m_worker = worker;
	}

	X3rdFuncWorker X3rdFunction::getWorker() const
	{
		return this->m_worker;
	}

	bool X3rdFunction::is3rd() const
	{
		return true;
	}

	Object * X3rdFunction::call(const X3rdArgs & args)
	{
		return m_worker(this,args);
	}


}