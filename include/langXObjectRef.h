#pragma once

namespace langX {
	
	class Object;
	class langXObject;

	/*
	 * langX ��������� 
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

		// ���õ��ĸ�object
		langXObject *m_object_ref = nullptr;
	};

}