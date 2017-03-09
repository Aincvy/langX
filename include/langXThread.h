#pragma once

#include "StackTrace.h"

#include <map>

namespace langX {

	// �߳���Ϣ
	class langXThread
	{
	public:
		langXThread();
		~langXThread();

		// ��õ�ǰ�ĵ���ջ
		StackTrace & getStackTrace();

	private:

		// �߳�id
		int m_thread_id;
		// ����ջ
		StackTrace m_stacktrace;



	};


	// �̹߳�����
	class langXThreadMgr
	{
	public:
		langXThreadMgr();
		~langXThreadMgr();

	private:

	};


}