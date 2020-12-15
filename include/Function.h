#pragma once

#include <stdarg.h>

#include "Object.h"

namespace langX {

    // 类声明
	class ClassInfo;
	class Environment;
	class ScriptEnvironment;
	class langXObject;
	class langXThread;

	// 部分属性

	/**
	 * 表示一个 空的参数列表， 此值并不是null， 只是 index = 0
	 */
    extern X3rdArgs* emptyArgs;


	// Function 相关的类声明

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
		// 一般不直接使用这个函数， 而是使用 FunctionRef 的函数
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

		/**
		 * 判断当前函数 是否是一个第三方函数
		 * @return   true: 是的， false: 不是 ^_^
		 */
		bool is3rd() const;

        /**
         * 调用这个第三方函数  ^v^
         * @param args   参数
         * @return 函数的执行结果
         */
		Object *call(const X3rdArgs &args);

		/**
		 * 调用当前这个第三方函数  @.@
		 * @param args   参数指针
		 * @return 函数的执行结果
		 */
		Object *call(X3rdArgs *args);


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
		langXObject *getObject() const;
		void setObject(langXObject *a);

		// 函数的类信息
		ClassInfo *getClassInfo() const;
		void setClassInfo(ClassInfo *a);

		// 如果这个函数来自一个 对象， 则会返回一个对象环境， 如果来自类， 则返回类桥接环境
		Environment *getFunctionEnv();

		/**
		 * 在 cpp层次调用这个函数
		 * @param args   参数列表
		 * @param remark
		 * @return
		 */
		Object *call(X3rdArgs *args, const char *remark );

		/**
		 * 在cpp层次调用这个函数
		 * @param thread
		 * @param args   参数列表
		 * @param remark
		 * @return
		 */
        Object *call(langXThread *thread, X3rdArgs *args, const char *remark );

        /**
         * 在 cpp 层次调用 这个函数
         * @param thread
         * @param remark
         * @param argc
         * @param ...
         * @return
         */
		Object *call(langXThread *thread, const char *remark, int argc, ...);

	private:

		void finalize();

		// 引用的是哪个函数
		Function *m_func = nullptr;

		//  对象函数引用。 比如  b=a.func ; 的时候， 这个m_func_obj 就指向了 a 的那个langXObject
		langXObject *m_func_obj = nullptr;
		//  类函数引用。  比如 b=a::func ;  的时候， 这个 m_func_class 就指向了 a 的类型
		ClassInfo *m_func_class = nullptr;

	};


	// 函数调用的方法

    /**
     * 复制一个 args 的内容到 一个 3rdArgs
     * @param args
     * @param _3rdArgs
     * @param object
     */
    void copyArgsTo3rdArgs(ArgsList *args, X3rdArgs *_3rdArgs, langXObject *object);

    /**
     * 赋值一个 va_list 到一个 3rdArgs 里面
     * @param ap
     * @param _3rdArgs
     * @param argc
     * @param object  将赋值给 X3rdArgs 得对象属性
     */
    void copyVaListTo3rdArgs(va_list ap, X3rdArgs & _3rdArgs, int argc, langXObject *object);

    /**
     * 添加函数的拓展变量到 函数内部 | $_, $1,$2 等
     * @param env
     * @param args
     */
    void addFunctionExtendsVar(Environment* env, X3rdArgs* args);


    Object *callFunction(langXThread *thread, Function *function, ArgsList *args, const char *remark);

    /**
	 * 执行函数
	 * @param thread
	 * @param function
	 * @param args
	 * @param remark
	 * @return
	 */
    Object *callFunction(langXThread *thread, Function *function, ArgsList *args, langXObject *object, const char *remark);

    // 执行函数， 本函数是上面那个的 扩展品
    Object *callFunction(langXThread *thread, Function *function, X3rdArgs *args, langXObject *object, const char *remark);

    /**
     *
     * @param function
     * @param args
     * @param remark
     * @return
     */
    Object *callFunction(Function *function, X3rdArgs *args, const char *remark);

    /**
     * 执行一个无参函数
     * @param function
     * @param remark
     * @return
     */
    Object *callFunction(Function *function, const char *remark);

	/**
	 * 调用函数
	 * @param function   要执行的函数
	 * @param args       参数列表
	 * @param remark     备注
	 * @param thread     线程对象
	 * @return
	 */
	Object *callFunction(langXThread *thread, Function *function, X3rdArgs *args, const char *remark);

    /**
     * 调用一个函数
     * @param thread
     * @param function
     * @param object       调用该函数所属的实例
     * @param remark
     * @param argc      输入的参数个数
     * @param ...       动态参数列表， 每个元素都需要放 Object*
     * @return
     */
    Object *callFunction(langXThread *thread, Function *function,langXObject *object,  const char *remark, int argc, ...);

    /**
     * 调用一个函数  给一个可变参数的列表
     * @param thread
     * @param function
     * @param object
     * @param remark
     * @param ap
     * @return
     */
    Object *vCallFunction(langXThread *thread, Function *function, langXObject *object, const char *remark, int argc,
                          va_list ap);


    /**
     * 调用函数
     * @param functionRef   函数引用
     * @param args          参数列表
     * @param remark        备注
     * @return
     */
    Object *callFunction(langXThread *thread, FunctionRef *functionRef, X3rdArgs *args, const char *remark);

    /**
     * 使用一个函数引用 调用函数
     * @param thread
     * @param functionRef
     * @param remark
     * @param argc
     * @param ...    可变参数列表
     * @return
     */
    Object *callFunction(langXThread *thread, FunctionRef *functionRef, const char *remark, int argc, ...);

    /**
     * 使用一个函数引用调用一个函数
     * @param thread
     * @param functionRef
     * @param remark
     * @param argc
     * @param ap    参数列表
     * @return
     */
    Object *vCallFunction(langXThread *thread, FunctionRef *functionRef, const char *remark, int argc, va_list ap);

    /**
     * 使用一个 函数引用来执行一个函数
     * @param thread
     * @param functionRef
     * @param args
     * @param remark
     * @return
     */
    Object *callFunction(langXThread *thread, FunctionRef *functionRef, ArgsList *args, const char *remark);





}