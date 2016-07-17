#pragma once
#include "Object.h"

namespace langX {
	class Function : public Object
	{
	public:
		Function();
		Function(Node *);
		~Function();

		// 获取参数个数
		int getArgsCount() const;
		
		Object *call() const;

	private:
		// 内部函数执行的根节点
		Node * m_node_root = nullptr;
	};

}