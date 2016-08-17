#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Function.h"

namespace langX {
	class Environment;
	class Allocator;

	class langXState
	{
	public:
		langXState();
		~langXState();

		void putObject(const char* , Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);

		/* ����һ���µĻ�����������ǰ��������Ϊ�û����ĸ��������� Ȼ�󽫸û�������Ϊ��ǰ���� */
		Environment* newEnv();
		// ��������Ϊ ��ǰ������ ����ԭ��ǰ������Ϊ ������ ��������
		Environment* newEnv(Environment *);
		/* �������˻�һ���������ǰֻ��һ����������ʲôҲ���� 
		  ����˻��ϼ������� ��ǰ�����ڵ����б������ڴ涼���ᱻ�ͷ� */
		void backEnv();

		Environment *getCurrentEnv() const;
		Environment *getGlobalEnv() const;

		// ע��һ������������
		void reg3rd(const char *, X3rdFuncWorker worker);
		// ���������ע��
		void unreg3rd(const char *);

		Allocator &getAllocator() const;

	private:
		// ȫ�ֻ���
		Environment *m_global_env = nullptr;
		Environment *m_current_env = nullptr;
		Allocator  *m_allocator = nullptr;

	};
}