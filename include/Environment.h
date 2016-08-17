#pragma once
#include <map>
#include <string>

namespace langX {

	class Object;
	class Function;
	class ClassInfo;

	/*
	 * ������  
	 * [��Ȼ��ʲô�� ������д - - ]
	 * ������ʾ�� һ������ �� ������һЩ������ ����
	 */
	class Environment
	{
	public:
		Environment();
		/* ���ͷ���������ʱ�򲢲���ʩ�����ĸ����������� */
		~Environment();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

		Environment *getParent() const;
		void setParent(Environment *);

		// �����޶�
		void setRestrict(bool);
		// �Ƿ��޶�
		bool isRestrict() const;

	private:
		std::map<std::string, Object*> m_objects_map;
		std::map<std::string, Function*> m_functions_map;
		std::map<std::string, Object*> m_classes_map;

		Environment *m_parent = nullptr;

		//  �Ƿ��޶��� ����޶��� ��Ѱ�ұ�����ʱ�򲻻�ȥѰ�Ҹ�������
		bool m_restrict = false;
	};


	// ����Žӻ���  
	class ClassBridgeEnv : public Environment
	{
	public:
		ClassBridgeEnv(ClassInfo *);
		~ClassBridgeEnv();

		void putObject(const char*, Object*);
		void putObject(const std::string &, Object*);
		Object* getObject(const std::string &);

		void putFunction(const char*, Function*);
		void putFunction(const std::string &, Function*);
		Function* getFunction(const std::string &);

	private:

		ClassInfo* m_class = NULL;
	};

}