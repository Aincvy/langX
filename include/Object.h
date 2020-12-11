#pragma once
#include <string>
#include <map>

#define SHOW_DETAILS 1

/*
*   创建时间：  2016-07-07
*   作者： Aincvy (aincvy@gmail.com)
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
	class XArray;

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
		// 参数: true 深度克隆 ,false: 只克隆引用
		// 目前只针对数组有效， 其他元素 都正常
		virtual Object* clone(bool) const;

		// 获得这个对象在他产生环境的名字
		const char * getName() const;
		// 设置这个对象在他产生环境中的名字
		void setName(std::string );

		/* 把自己Update 成目标的值
		   这个函数不应该， 也不会update 所在的环境   */
		virtual void update(Object *) = 0;

		// 返回这个对象的特性字符串  | 相当于唯一标识的意思
		virtual const char * characteristic() const;

		// 设置这个对象的特性字符串  | 相当于唯一标识的意思
		void setCharacteristic(const char *);
		// 重新生成一个新的 特性字符串， 并返回
		const char * regenCharacteristic();

	protected:
		// 这个对象的特性字符串   | 相当于唯一标识的意思
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
	    // 变量的名字
		char * name;
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
		// 数组元素节点
		NODE_ARRAY_ELE ,
		// int 类型数据的节点
		NODE_CONSTANT_INTEGER ,
	};

	// 节点的状态， 比如： 正常，在循环内，在函数内
	struct NodeState
	{
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
		// case 列表  
		Node **caseList;
		// key: case 'key'  , value: caseList 的索引
		std::map<std::string, int>  keyIndexMap;
		// 当前索引
		int nowIndex;
		// 一个list指针
		void *list_ptr;
	};

	// 节点的文件信息
	struct NodeFileInfo
	{
		// 文件名
		// const char * filename;
		// 修改成 std::string 试试，上面的那个类型要处理一下
		std::string filename;
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

	};

	struct Node
	{
		NodeType type;
		// 在执行结束之后是否进行 free 操作
		bool freeOnExecuted;
		// 当前节点的值 .  如果当前结点是一个常量数字， 则free 的时候会施放这个值得内存
		Object *value;
		// 万能指针 ， 主要用于放置参数什么的
		void *ptr_u;
		// 节点状态
		NodeState state;
		// 当前节点所在的文件信息
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

	// 这是基于节点的 实参列表
	struct ArgsList
	{
	    // 每个节点是一个参数
		Node *args[PARAM_COUNT];
		// 实参索引
		int index;
	};

	// 在cpp层面调用函数使用的参数列表
	struct X3rdArgs
	{
	    // 实参列表
		Object *args[PARAM_COUNT];
		// 实参索引, 一般表示 数量了
		int index;

		// 调用函数的那个对象 当函数不是类的函数， 或者静态调用的时候， 此值为 nullptr
		langXObject * object = nullptr;
	};

	//  节点链， 主要是做执行链用的
	struct NodeLink {
		Node * node;
		struct NodeLink *next;     // 下一个节点，此属性好像没什么用
		struct NodeLink *previous;  // 上一个节点 ， 一般指调用这个节点的节点
		int index;       // 索引， 可能针对于父节点使用的
		bool flag;       // 一个标记，不同的场景不同的含义
		bool backAfterExec;             // 执行结束之后 退回到父节点
		Environment *tryEnv;            // try 环境， 在try 节点下有值，其他为null 

		void * ptr_u;              // 万能指针， 可以指向任何单位  | 正常情况下， 其他逻辑并不会主动操作这个指针
	};


	// 申请一个 node link
	NodeLink * newNodeLink(NodeLink *, Node *);
	// 释放一个nodeLink 占用的内存
	void freeNodeLink(NodeLink *);

} 