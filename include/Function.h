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

		// 获取参数个数
		int getArgsCount() const;
		
		Object *call() const;

		bool isTrue() const;
		ObjectType getType() const;
		/* 函数返回一个自己的指针 */
		Object* clone() const;
		void update(Object *);

	private:
		// 内部函数执行的根节点
		Node * m_node_root = nullptr;
		char * m_name;
		ParamsList * m_params_list = nullptr;

		void finalize();
	};

}