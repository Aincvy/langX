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

		// 当前变量是否是一个 local 变量
		bool isLocal() const;
		// 当前变量是否是一个 private 变量
		bool isPrivate() const;
		// 当前变量是否是一个 public 变量
		bool isPublic() const;

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

		bool m_is_local = false;
		bool m_is_private = false;
		bool m_is_public = false;
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

	// 节点的状态， 比如： 正常，在循环内，在函数内
	struct NodeState
	{
		// 在循环内的语句
		bool in_loop;
		// 在函数内的语句
		bool in_func;
		// 在switch 语句中
		bool in_switch;

		// 是否在 break 状态
		bool isBreak;
		// 是否在 return 状态
		bool isReturn;
		// 在case 的时候是否需要计算case 的条件
		bool isCaseNeedCon;
		// 是否是后缀
		bool isSuffix;
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
		// 节点状态
		NodeState state;
		// 后置值 ， 如果当前节点为一个 变量节点， 当前属性则为有用
		Object *postposition;

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

	struct X3rdArgs
	{
		Object *args[PARAM_COUNT];
		// 实参索引, 一般表示 数量了
		int index;
	};
}