#pragma once
#include <string>

#define SHOW_DETAILS 1

/*
*   创建时间：  2016-07-07
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     表示一个 langX 基础对象 
*/

namespace langX {

//  参数的个数
#define PARAM_COUNT 30

	class Environment;
	class langXObject;
	class XArrayRef;

	// 对象类型
	enum ObjectType
	{
		UNKNOWN=100, NUMBER , STRING, FUNCTION, OBJECT , NULLOBJECT ,XARRAY  
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
		// 当前变量是否是一个 const 变量
		bool isConst() const;

		// 设置此变量的常量属性
		void setConst(bool);
		// 设置
		void setLocal(bool);

		// 获得这个object 产生的环境
		Environment *getEmergeEnv() const;
		// 设置
		void setEmergeEnv(Environment *);

		/* 当前值可以表示为真么？  null,0,false 都不会表示为真  */
		virtual bool isTrue() const = 0;
		/* 获得当前对象的类型  */
		virtual ObjectType getType() const = 0;
		/* 克隆当前对象， 返回出一个新的对象 */
		virtual Object* clone() const = 0;

		// 获得这个对象在他产生环境的名字
		const char * getName() const;
		// 设置这个对象在他产生环境中的名字
		void setName(std::string );

		/* 把自己Update 成目标的值
		   这个函数不应该， 也不会update 所在的环境   */
		virtual void update(Object *) = 0;

		// 返回这个对象的特性字符串
		virtual const char * characteristic() const;

		// 设置这个对象的特性字符串
		void setCharacteristic(const char *);

	protected:
		// 这个对象的特性字符串
		mutable std::string m_characteristic;

	private:
		int m_ref_count;

		/* 命名借用了java 里面的命名， 好像意思是定案，
		在当前语境下， 这个函数应该完成的功能为： 干掉自己   
		2016-08-18:  我很想知道这个函数有个鸟用。。   */
		virtual void finalize() = 0;

		// 这个object 出现的环境 ， 根的位置
		Environment *m_emerge_env = nullptr;

		// 这个对象在出现环境中的名字
		std::string m_name;

		bool m_is_local = false;
		bool m_is_private = false;
		bool m_is_public = false;
		bool m_is_const = false;
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
		NODE_ARGS  ,
		// 函数节点 （函数声明）  当节点类型是函数的时候， 函数引用在node->value 上
		NODE_FUNCTION,
		// 类节点 （类声明） 当节点类型为 类的时候， 类引用在 node->ptr_u  上面
		NODE_CLASS ,
		// 空引用节点
		NODE_NULL  ,
		// 数组声明节点.  当为数组节点的时候。 数组基本信息存放在  node->ptr_u  上面。 执行完需要用free 释放
		NODE_ARRAY ,
		// 数组元素节点
		NODE_ARRAY_ELE ,
		// int 类型数据的节点
		NODE_CONSTANT_INTEGER ,
		// 切换命名空间
		NODE_CHANGE_NAMESPACE 
	};

	// 节点的状态， 比如： 正常，在循环内，在函数内
	struct NodeState
	{
		// 是否在 break 状态
		bool isBreak;
		// 是否在 return 状态
		bool isReturn;
		// 是否执行了 continue 
		bool isContinue;
		// 在case 的时候是否需要计算case 的条件
		bool isCaseNeedCon;
		// 是否是后缀
		bool isSuffix;

		// 是否自动扩充前类
		bool classAuto;
		// 是否为 local 属性
		bool isLocal;
	};

	struct Node;
	// 有关switch 相关的内容
	struct SwitchInfo
	{
		// default 语句的节点所在位置
		Node *defaultNode;

		// 当前结点是否是 default 语句
		bool isDefault;
		// case 语句是否进入内容
		bool isInCase;
		// 如果当前节点是 default ,是否执行
		bool doDefault;
	};

	// 节点的文件信息
	struct NodeFileInfo
	{
		// 文件名
		const char * filename;
		// 行号
		int lineno;
	};

	struct Constant
	{
		int iValue;
		double dValue;
		char* sValue;
		char cValue;
	};

	// 数组声明时使用
	struct XArrayNode
	{
		// 数组名字
		char * name;
		// 数组长度
		int length;
		// 变量长度索引 . 如果变量索引节点存在， 则使用这个， 否则使用 length 
		Node * lengthNode;
	};

	// 数组信息
	struct ArrayInfo
	{
		// 数组的名字
		char *name;
		// 数组的索引
		int index;
		// 变量索引 . 如果变量索引节点存在， 则使用这个， 否则使用 index 
		Node * indexNode;
		// 对象节点， 运算这个节点可以获得一个数组对象
		Node * objNode;
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
		// switch 相关的内容
		SwitchInfo switch_info;
		// 节点状态
		NodeState state;
		// 文件信息
		NodeFileInfo fileinfo;
		// 后置值 ， 如果当前节点为一个 变量节点， 当前属性则为有用
		Object *postposition;

		Variable *var_obj;
		Constant *con_obj;
		Operator *opr_obj;
		ArrayInfo *arr_obj;
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

		XArrayRef *arrayRef = nullptr;
		langXObject * object = nullptr;
	};
}