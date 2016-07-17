#pragma once
#include "Object.h"

namespace langX {
	class Function : public Object
	{
	public:
		Function();
		Function(Node *);
		~Function();

		// ��ȡ��������
		int getArgsCount() const;
		
		Object *call() const;

	private:
		// �ڲ�����ִ�еĸ��ڵ�
		Node * m_node_root = nullptr;
	};

}