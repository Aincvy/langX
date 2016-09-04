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

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);
		// 只从自己的环境中寻找对象
		Object* getObjectSelf(const char *) const;

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

		void putClass(const char *, ClassInfo *);
		ClassInfo *getClass(const char *);

		void putNameSpace(const char *, XNameSpace *);
		XNameSpace * getNameSpace(const char *);

		// 获得命名空间， 如果命名空间不存在， 则创建一个放入自身中
		XNameSpace * getNameSpace2(const char *);

	private:

		std::string m_name;

		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, ClassInfo*> m_classes_map;
		std::map<std::string, XNameSpace*> m_namespace_map;

	};


}