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

	Function::~Function()
	{

	}

	int Function::getArgsCount() const
	{
		return 0;
	}

	Object * Function::call() const
	{
		if (m_node_root == nullptr)
		{
			return;
		}

		__execNode(m_node_root);
		return nullptr;
	}

}