#pragma once
#include "Object.h"

namespace langX {
	class Function : public Object
	{
	public:
		Function();
		Function(Node *);
		Function(char*,Node *);
		~Function();

		const char* getName() const;
		void setName(char*);

		// 获取参数个数
		int getArgsCount() const;
		
		Object *call() const;

		bool isTrue() const;
		ObjectType getType() const;

	private:
		// 内部函数执行的根节点
		Node * m_node_root = nullptr;
		char * m_name;
	};

}