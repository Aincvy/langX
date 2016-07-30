#pragma once
#include <map>
#include <string>
#include "Object.h"
#include "Environment.h"
#include "Allocator.h"

namespace langX {
	class langXState
	{
	public:
		langXState();
		~langXState();

		void putObject(const char* , Object*);
		void putObject(const std::string &, Object*);
		Object * getObject(const std::string &);

		/* ����һ���µĻ�����������ǰ��������Ϊ�û����ĸ��������� Ȼ�󽫸û�������Ϊ��ǰ���� */
		Environment *newEnv();
		/* �������˻�һ���������ǰֻ��һ����������ʲôҲ���� */
		void backEnv();

		Environment *getCurrentEnv() const;
		Environment *getGlobalEnv() const;

		Allocator &getAllocator() const;

	private:
		// ȫ�ֻ���
		Environment *m_global_env = nullptr;
		Environment *m_current_env = nullptr;
		Allocator  *m_allocator = nullptr;

	};
}