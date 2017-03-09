#include "../include/langXThread.h"

namespace langX {



	langXThread::langXThread()
	{
	}

	langXThread::~langXThread()
	{
	}

	StackTrace & langXThread::getStackTrace()
	{
		return this->m_stacktrace;
	}

	langXThreadMgr::langXThreadMgr()
	{
	}

	langXThreadMgr::~langXThreadMgr()
	{
	}

}