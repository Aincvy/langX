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

		//  获得引用的是哪个object
		langXObject *getRefObject();

		void setMember(const char*, Object *);
		Object * getMember(const char *) const;
		Function *getFunction(const char *) const;


		// 获得类信息
		const ClassInfo * getClassInfo() const;

		// 获得构造函数
		Function * getConstructor() const;
		
		// 设置这个对象的成员的产生环境
		void setMembersEmergeEnv(Environment *);

		bool isTrue() const;
		ObjectType getType() const;
		Object* clone() const;
		//  更新当前引用， 引用到另外一个对象身上
		void update(Object *);

		// 设置当前引用的是哪个对象
		void setRefObject(langXObject *);

	private:
		void finalize();

		// 引用的哪个object
		langXObject *m_object_ref = nullptr;
	};

}