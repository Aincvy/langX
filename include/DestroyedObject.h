#pragma once


namespace langX {

	/* @date  2016-10-18 添加
	   @desc  被回收的系统对象， 他的引用都会变成这个对象。  如果 对象a 被用户手动进行了delete 操作。 那么 所有指向a的引用都会变成这个对象
	*/

	class Object;

	//  被销毁的对象 
	class DestroyedObject : public Object
	{
	public:
		DestroyedObject();
		~DestroyedObject();


		/* 当前值可以表示为真么？  null,0,false 都不会表示为真  */
		bool isTrue() const ;
		/* 获得当前对象的类型  */
		ObjectType getType() const ;
		/* 克隆当前对象， 返回出一个新的对象 */
		Object* clone() const ;


		/* 把自己Update 成目标的值
		这个函数不应该， 也不会update 所在的环境   */
		void update(Object *) ;


	private:

		// 销毁自身
		void finalize();

	};

}