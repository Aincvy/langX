#pragma once

/*
*   创建时间：  2016-07-07
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     表示一个 langX 对象 
*/

namespace langX {

//  参数的个数
#define PARAM_COUNT 30


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

		/* 自增当前对象的引用次数 */
		void incRefCount();
		/* 自减当前对象的引用次数， 如果当前对象的引用次数小于等于0  ， 则销毁当前对象   */
		void decRefCount();

		/* 当前值可以表示为真么？  null,0,false 都不会表示为真  */
		virtual bool isTrue() const = 0;
		/* 获得当前对象的类型  */
		virtual ObjectType getType() const = 0;
		/* 克隆当前对象， 返回出一个新的对象 */
		virtual Object* clone() const = 0;

		/* 把自己Update 成目标的值 */
		virtual void update(Object *) = 0;

	private:
		int m_ref_count;

		/* 命名借用了java 里面的命名， 好像意思是定案，
		在当前语境下， 这个函数应该完成的功能为： 干掉自己   */
		virtual void finalize() = 0;
	};

	struct Variable
	{
		char * name;
		
		// 07-23 注释  统一将节点的运算结果放在 Node.value 中
		// 这个变量的值，   这个对象 在FreeNode 函数中并不会释放
		//Object *obj;
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
		NODE_OPERATOR ,
		// 实参节点   
		NODE_ARGS 
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
		// 临时存放bool 结果
		bool bool_value;

		// 07-23 注释， 结果放在 Node.value 中
		// 当前操作产生的结果, 这个对象 在FreeNode 函数中并不会释放
		//Object *obj;
	};

	struct Node
	{
		NodeType type;
		// 在执行结束之后是否进行 free 操作
		bool freeOnExeced;
		// 当前节点的值 .  如果当前结点是一个常量数字， 则free 的时候会施放这个值得内存
		Object *value;
		// 万能指针 ， 主要用于放置参数什么的
		void *ptr_u;

		Variable *var_obj;
		Constant *con_obj;
		Operator *opr_obj;
	};

	// 参数列表 ,最大不超过30个参数
	struct ParamsList
	{
		char* args[PARAM_COUNT];
		// 参数索引
		int index;
	};

	// 这是实参
	struct ArgsList
	{
		Node *args[PARAM_COUNT];
		// 实参索引
		int index;
	};
}