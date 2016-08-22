#include "../include/StackTrace.h"
#include "../include/Function.h"
#include "../include/ClassInfo.h"

namespace langX {



	StrackTraceFrame::StrackTraceFrame()
	{
	}

	StrackTraceFrame::~StrackTraceFrame()
	{
	}

	void StrackTraceFrame::setRemark(const char *a)
	{
		this->m_remark = std::string(a);
	}

	const char * StrackTraceFrame::getRemark() const
	{
		return this->m_remark.c_str();
	}

	void StrackTraceFrame::setClassInfo(ClassInfo *a)
	{
		this->m_class_info = a;
	}

	const ClassInfo & StrackTraceFrame::getClassInfo() const
	{
		return *this->m_class_info;
	}

	void StrackTraceFrame::setFunction(Function *a)
	{
		this->m_function = a;
	}

	const Function & StrackTraceFrame::getFunction() const
	{
		return *this->m_function;
	}

	const char * StrackTraceFrame::getInfo() const
	{

		return nullptr;
	}

	StackTrace::StackTrace()
	{
		
	}

	StackTrace::~StackTrace()
	{
		while (!this->m_frames.empty()) {
			delete this->m_frames.front();
			this->m_frames.pop();
		}
	}

	StrackTraceFrame * StackTrace::newFrame(ClassInfo *a, Function *b, const char *c)
	{
		StrackTraceFrame *f = new StrackTraceFrame();
		f->setClassInfo(a);
		f->setFunction(b);
		f->setRemark(c);

		this->m_frames.push(f);

		return f;
	}

	StrackTraceFrame * StackTrace::popFrame()
	{
		if (this->m_frames.empty())
		{
			return NULL;
		}

		StrackTraceFrame  *ret = this->m_frames.front();
		this->m_frames.pop();
		return ret;
	}

	StrackTraceFrameArray StackTrace::frames() const
	{
		StrackTraceFrameArray ret;
		
		return StrackTraceFrameArray();
	}

}