#pragma once

namespace langX {
	class Object;
	class ClassInfo;
	class Environment;
	class ScriptEnvironment;
	class langXObject;
	struct NodeLink;

	/* 0924  现在函数不在继承自Object . 而是添加一个新的 类型 FunctionRef 继承自Object */
	class Function 
	{
	public:
		Function();
		Function(Node *);
		Function(const char*,Node *);
		~Function();

		const char* getName() const;
		void setName(const char*);

		void setParamsList(ParamsList *);
		ParamsList *getParamsList() const;

		ClassInfo *getClassInfo() const;
		void setClassInfo(ClassInfo *);

		// 获取参数个数
		int getArgsCount() const;
		
		// 调用这个函数， 在调用这个方法之前得确保参数都放入了最近的一个环境里面 
		Object *call() const;

		// 是否是第三方函数
		virtual bool is3rd() const;
		// 当前函数是否有名字
		bool hasName() const;

		// 这个函数所属脚本的相关处理
		void setScriptEnv(ScriptEnvironment *);
		ScriptEnvironment * getScriptEnv() const;

	private:
		// 内部函数执行的根节点
		Node * m_node_root = nullptr;
		char * m_name = nullptr;
		ParamsList * m_params_list = nullptr;
		// 当前函数是属于哪个类
		ClassInfo *m_class_info = nullptr;
		// 这个函数所属的脚本环境
		ScriptEnvironment * m_script_env = nullptr ;

		// 私有函数?
		bool m_private = false;
		// 本地函数? 
		bool m_local = false;
		// 共有函数 ?
		bool m_public = true;
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


	/* langX Object.  表示一个函数引用 */
	class FunctionRef : public Object
	{
	public:
		FunctionRef(Function *);
		~FunctionRef();


		bool isTrue() const;
		ObjectType getType() const;
		/* 函数返回一个自己的指针 */
		Object* clone() const;
		void update(Object *);

		// 获得引用是哪个函数
		Function * getRefFunction();


		//  函数的对象
		langXObject *getObj() const;
		void setObj(langXObject *);

		// 函数的类信息
		ClassInfo *getClaxx() const;
		void setClaxx(ClassInfo *);

		// 如果这个函数来自一个 对象， 则会返回一个对象环境， 如果来自类， 则返回类桥接环境
		Environment *getFunctionEnv();

		// 调用这个函数  更多解释请查看   YLlangX.h 中 callFunction 函数的说明！
		Object *call(ArgsList *argsList, const char *remark, NodeLink *);

		//  参数为1 参数数组， 参数2为数组的元素个数 参数3为 备注
		//  此函数内部实现会对参数进行 克隆然后再使用
		Object *call(Object* [] ,int , const char *remark);

	private:

		void finalize();

		// 引用的是哪个函数
		Function *m_func = nullptr;

		//  对象函数引用。 比如  b=a.func ; 的时候， 这个m_func_obj 就指向了 a 的那个langXObject
		langXObject *m_func_obj = nullptr;
		//  类函数引用。  比如 b=a::func ;  的时候， 这个 m_func_claxx 就指向了 a 的类型
		ClassInfo *m_func_claxx = nullptr;

	};

}