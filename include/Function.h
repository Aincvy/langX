#pragma once

namespace langX {
	class Object;

	class Function : public Object
	{
	public:
		Function();
		Function(Node *);
		Function(const char*,Node *);
		~Function();

		const char* getName() const;
		void setName(const char*);

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

		// �Ƿ��ǵ���������
		virtual bool is3rd() const;

	private:
		// �ڲ�����ִ�еĸ��ڵ�
		Node * m_node_root = nullptr;
		char * m_name;
		ParamsList * m_params_list = nullptr;

		void finalize();
	};


	class X3rdFunction;
	class langXState;

	//  ������������ ����ָ��
	typedef Object *(*X3rdFuncWorker)(X3rdFunction * , const X3rdArgs &);

	// ���������� ���ⲿע������ĺ��� 
	class X3rdFunction : public Function
	{
	public:
		X3rdFunction();
		~X3rdFunction();

		void setLangX(langXState *);
		langXState * getLangX() const  ;

		// ���õ�����������ʵ��ִ����
		void setWorker(X3rdFuncWorker worker);
		// ��ȡ
		X3rdFuncWorker getWorker() const; 

		bool is3rd() const;
		Object *call(const X3rdArgs &);
	private:
		X3rdFuncWorker m_worker;
		langXState *m_state;
	};

}