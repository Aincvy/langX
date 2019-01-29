#pragma once
#include "Object.h"

namespace langX {

	class XArrayRef;

	/*  数组必须先声明之后才能使用 */

	//  数组
	class XArray
	{
	public:

		// 使用者应该使用 Allocator::allocateArray() 函数来申请一个数组， 而不是直接 new 
		XArray(int length);
		~XArray();

		int getLength() const;

		Object * at(int index) const;

		// 在set 的时候会获得一个 obj 的副本
		void set(int index, Object *);

		// 添加一个对象到末尾
		bool add(Object *);

		// 只是自增一个自己的引用次数
		//void justAddRef();
		// 生成一个引用， 引用到这个对象身上
		XArrayRef * addRef();
		//  减少一个引用
		void subRef();
		//  获得当前对象的引用次数
		int getRefCount() const;

		// 克隆当前数组 | 深度克隆
		XArray *clone() const;

	private:
		Object** m_array = nullptr;
		int m_length = 0;
		// 调用添加函数的时候 游标
		int m_add_cursor = 0;

		int  m_ref_count = 0;
	};

	// 写一起吧先。  数组引用
	class XArrayRef : public Object
	{
	public:
		XArrayRef(XArray * );
		~XArrayRef();

		XArray * getArray() const;

		Object * at(int index) const;
		// 在set 的时候会获得一个 obj 的副本
		void set(int index, Object *);
		int getLength() const;

		/* 当前值可以表示为真么？  null,0,false 都不会表示为真  */
		bool isTrue() const ;
		/* 获得当前对象的类型  */
		ObjectType getType() const ;
		/* 克隆当前对象， 返回出一个新的对象 */
		Object* clone() const ;
		Object* clone(bool) const;

		/* 把自己Update 成目标的值
		这个函数不应该， 也不会update 所在的环境   */
		void update(Object *) ;

	private:

		void finalize();

		XArray* m_array;

	};


}