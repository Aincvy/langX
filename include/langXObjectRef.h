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
		langXObjectRef(langXObject *);
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