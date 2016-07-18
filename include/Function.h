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

		// ��ȡ��������
		int getArgsCount() const;
		
		Object *call() const;

		bool isTrue() const;
		ObjectType getType() const;

	private:
		// �ڲ�����ִ�еĸ��ڵ�
		Node * m_node_root = nullptr;
		char * m_name;
	};

}