#pragma once

namespace langX {
	
	class Object;
	class langXObject;

	/*
	 * langX 对象的引用 
	*/
	class langXObjectRef : public Object
	{
	public:
	    // 构造的时候并不增加 对象的引用次数。  但是析构的时候会减少对象的引用次数
		langXObjectRef(langXObject *);
		// 构造的时候并不增加 对象的引用次数。  但是析构的时候会减少对象的引用次数
		~langXObjectRef();

		bool isTrue() const;
		ObjectType getType() const;
		Object* clone() const;
		void update(Object *);

	private:
		void finalize();

		// 引用的哪个object
		langXObject *m_object_ref = nullptr;
	};

}