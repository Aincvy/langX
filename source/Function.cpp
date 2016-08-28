#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/Object.h"
#include "../include/ExecNode.h"
#include "../include/langX.h"
#include "../include/Function.h"
#include "../include/Allocator.h"
#include "../include/YLlangX.h"
#include "../include/ClassInfo.h"


langX::Allocator m_exec_alloc;
extern void deal_state(langX::NodeState * state);
extern void deal_switch_info(langX::SwitchInfo *si);

void resetNodeState(langX::Node *n) {
	deal_state(&n->state);
	deal_switch_info(&n->switch_info);
	if (n->value != NULL)
	{
		m_exec_alloc.free(n->value);
		n->value = NULL;
	}
	// ptr_u 可能存放了参数， 等以后有问题的时候再进行调整，  0821
	//n->ptr_u = NULL;
	n->postposition = NULL;
	n->state.in_func = true;

	if (n->type == langX::NODE_OPERATOR)
	{
		for (int i = 0; i < n->opr_obj->op_count; i++)
		{
			langX::Node *t = n->opr_obj->op[i];
			if (t == NULL)
			{
				continue;
			}

			resetNodeState(t);
		}
	}
}

namespace langX {

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
		if (this->m_node_root != NULL)
		{
			this->m_node_root->freeOnExeced = true;
			freeNode(this->m_node_root);
			this->m_node_root = NULL;
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

	ClassInfo * Function::getClassInfo() const
	{
		return this->m_class_info;
	}

	void Function::setClassInfo(ClassInfo *a)
	{
		this->m_class_info = a;
	}

	ParamsList * Function::getParamsList() const
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

		resetNodeState(this->m_node_root);

		//m_node_root->state.in_func = true;
		__execNode(m_node_root);

		if (m_node_root->value != NULL)
		{
			Object * obj = m_node_root->value->clone();
			m_exec_alloc.free(m_node_root->value);
			m_node_root->value = NULL;
			return obj;
		}
		return nullptr;
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
		return const_cast<Function*>(this);
	}

	void Function::update(Object *)
	{
		// do nothing
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