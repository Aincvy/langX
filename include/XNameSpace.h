#pragma once
#include <string>
#include <map>

namespace langX {

	class Function;
	class ClassInfo;
	class Object;

	class XNameSpace
	{
	public:
		XNameSpace(const char *);
		~XNameSpace();

		const char * getName() const;

		//  放入一个对象的copy 到 指定的key 上
		void putObject(const char*, Object*);
		//  放入一个对象的copy 到 指定的key 上
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);
		// 只从自己的环境中寻找对象
		Object* getObjectSelf(const char *) const;

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

		void putClass(ClassInfo *);
		void putClass(const char *, ClassInfo *);
		ClassInfo *getClass(const char *);

		void putNameSpace(const char *, XNameSpace *);
		// 获得这个命名空间的子命名空间  | 不支持以 . 分割的字符串
		XNameSpace * getNameSpace(const char *);

		// 获得命名空间， 如果命名空间不存在， 则创建一个放入自身中
		XNameSpace * getNameSpace2(const char *);

		void addRefNamespace(XNameSpace*);

	private:

		std::string m_name;

		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, ClassInfo*> m_classes_map;
		std::map<std::string, XNameSpace*> m_namespace_map;

		// 引用其他的命名空间
		std::map<std::string, XNameSpace*> m_ref_namespace_map;

	};


}