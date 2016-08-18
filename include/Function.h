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

		// 获取参数个数
		int getArgsCount() const;
		
		Object *call() const;

		bool isTrue() const;
		ObjectType getType() const;
		/* 函数返回一个自己的指针 */
		Object* clone() const;
		void update(Object *);

		// 是否是第三方函数
		virtual bool is3rd() const;

	private:
		// 内部函数执行的根节点
		Node * m_node_root = nullptr;
		char * m_name;
		ParamsList * m_params_list = nullptr;

		void finalize();
	};


	class X3rdFunction;
	class langXState;

	//  第三方函数的 函数指针
	typedef Object *(*X3rdFuncWorker)(X3rdFunction * , const X3rdArgs &);

	// 第三方函数 ，外部注册进来的函数 
	class X3rdFunction : public Function
	{
	public:
		X3rdFunction();
		~X3rdFunction();

		void setLangX(langXState *);
		langXState * getLangX() const  ;

		// 设置第三方函数的实质执行体
		void setWorker(X3rdFuncWorker worker);
		// 获取
		X3rdFuncWorker getWorker() const; 

		bool is3rd() const;
		Object *call(const X3rdArgs &);
	private:
		X3rdFuncWorker m_worker;
		langXState *m_state;
	};

}