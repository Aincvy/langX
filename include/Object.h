#pragma once

/*
*   创建时间：  2016-07-07
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     表示一个 langX 对象 
*/

namespace langX {


	// 对象类型
	enum ObjectType
	{
		UNKNOWN=100, NUMBER , STRING, FUNCTION
	};


	class Object
	{
	public:
		Object();
		~Object();

		/* 当前值可以表示为真么？  null,0,false 都不会表示为真  */
		virtual bool isTrue() const = 0;
		/* 获得当前对象的类型  */
		virtual ObjectType getType() const = 0;
	private:

	};

	struct Variable
	{
		char * name;
		// 这个变量的值，   这个对象 在FreeNode 函数中并不会释放
		Object *obj;
	};

	enum NodeType
	{
		// 数字常量节点
		NODE_CONSTANT_NUMBER = 50,
		// 字符串常量节点
		NODE_CONSTANT_STRING,
		// 变量节点
		NODE_VARIABLE ,
		// 操作符节点
		NODE_OPERATOR
	};

	struct Constant
	{
		int iValue;
		double dValue;
		char* sValue;
		char cValue;
	};

	struct Operator
	{
		// 我也不知道这啥
		struct Node** op;
		int op_count;
		// 操作符是什么
		int opr;
		// 当前操作产生的结果, 这个对象 在FreeNode 函数中并不会释放
		Object *obj;
		// 临时存放bool 结果
		bool bool_value;
	};

	struct Node
	{
		NodeType type;
		// 在执行结束之后是否进行 free 操作
		bool freeOnExeced;

		Variable *var_obj;
		Constant *con_obj;
		Operator *opr_obj;
	};

	// 参数列表 ,最大不超过30个参数
	struct ArgsList
	{
		char* args[30];
		// 参数索引
		int index;
	};
}