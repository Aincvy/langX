#include "../include/Object.h"
#include "../include/Function.h"
#include "../include/ClassInfo.h"
#include "../include/StackTrace.h"

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
		this->m_info.clear();
		bool flag = false;

		if (this->m_class_info)
		{
			this->m_info += this->m_class_info->getName();
			flag = true;
		}

		if (this->m_function)
		{
			if (flag)
			{
				this->m_info += ".";
			}

			this->m_info += this->m_function->getName();
			this->m_info += "()";
			flag = true;
		}

		if (!this->m_remark.empty())
		{
			this->m_info += "[";
			this->m_info += this->m_remark.c_str();
			this->m_info += "]";
		}

		return this->m_info.c_str();
	}

	StackTrace::StackTrace()
	{
	}

	StackTrace::~StackTrace()
	{
		auto i = this->m_frames.begin();
		while (i != this->m_frames.end())
		{
			delete (*i);
			i++;
		}

		this->m_frames.clear();
	}


    StrackTraceFrame *StackTrace::newFrame(Function *function, const char *remark) {
        return newFrame(function->getClassInfo(), function, remark);
    }

	StrackTraceFrame * StackTrace::newFrame(ClassInfo *classInfo, Function *function, const char *remark)
	{
		//printf("newFrame class: %s(%p), function: %s.\n" , (classInfo ? classInfo->getName() : "null"),classInfo, ( function ? function->getName() : "null"));

		StrackTraceFrame *f = new StrackTraceFrame();
		f->setClassInfo(classInfo);
		f->setFunction(function);
		f->setRemark(remark);

		// 追加到尾部
		this->m_frames.push_back(f);

		return f;
	}

	void StackTrace::popFrame()
	{
		if (this->m_frames.empty())
		{
			return;
		}

		StrackTraceFrame  *ret = this->m_frames.back();
		this->m_frames.pop_back();
		delete ret;
		return;
	}

	StrackTraceFrame * StackTrace::top() const
	{
		if (this->m_frames.empty())
		{
			return NULL;
		}

		return this->m_frames.back();
	}

	StrackTraceFrameArray StackTrace::frames() const
	{
		StrackTraceFrameArray ret;
		ret.length = this->m_frames.size();
		ret.frame = (const StrackTraceFrame**)calloc(ret.length, sizeof(StrackTraceFrame*));

		for (int i = 0; i < this->m_frames.size(); i++)
		{
			ret.frame[i] = this->m_frames[i];
		}

		return (ret);
	}


}