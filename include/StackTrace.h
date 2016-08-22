#pragma once
#include <string>
#include <queue>

/*
 * date: 2016-08-22  ,filename: StackTrace.h
 * author:  hideDragon
 * desc:  ��ջ����
 */

namespace langX {

	class ClassInfo;
	class Function;

	// ��ջ���ٵ�һ֡
	class StrackTraceFrame
	{
	public:
		StrackTraceFrame();
		~StrackTraceFrame();

		void setRemark(const char*);
		const char* getRemark() const;

		void setClassInfo(ClassInfo *);
		const ClassInfo & getClassInfo() const;

		void setFunction(Function *);
		const Function & getFunction() const;

		// ��õ�ǰ����֡����Ϣ
		const char * getInfo() const;

	private:

		// ��ע
		std::string m_remark;

		ClassInfo * m_class_info = nullptr;
		Function *m_function = nullptr;

	};

	struct StrackTraceFrameArray
	{
		StrackTraceFrame * frame;
		int length;
	};

	// ��ջ����
	class StackTrace
	{
	public:
		StackTrace();
		~StackTrace();

		//  ����һ���µ�֡
		StrackTraceFrame *newFrame(ClassInfo *, Function *, const char *);

		// ȡ��ջ����֡ (���Ƴ�)
		StrackTraceFrame *popFrame();

		// ���֡����
		StrackTraceFrameArray frames() const;

	private:

		std::queue<StrackTraceFrame*> m_frames;
	};


}