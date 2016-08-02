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

		void setParamsList(ParamsList *);
		ParamsList *getParamsList();

		// ��ȡ��������
		int getArgsCount() const;
		
		Object *call() const;

		bool isTrue() const;
		ObjectType getType() const;
		/* ��������һ���Լ���ָ�� */
		Object* clone() const;
		void update(Object *);

	private:
		// �ڲ�����ִ�еĸ��ڵ�
		Node * m_node_root = nullptr;
		char * m_name;
		ParamsList * m_params_list = nullptr;

		void finalize();
	};

}