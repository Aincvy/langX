#pragma once
#include <string>
#include <queue>

/*
 * date: 2016-08-22  ,filename: StackTrace.h
 * author:  hideDragon
 * desc:  堆栈跟踪
 */

namespace langX {

	class ClassInfo;
	class Function;

	// 堆栈跟踪的一帧
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

		// 获得当前调用帧的信息
		const char * getInfo() const;

	private:

		// 备注
		std::string m_remark;

		ClassInfo * m_class_info = nullptr;
		Function *m_function = nullptr;

	};

	struct StrackTraceFrameArray
	{
		StrackTraceFrame * frame;
		int length;
	};

	// 堆栈跟踪
	class StackTrace
	{
	public:
		StackTrace();
		~StackTrace();

		//  生成一个新的帧
		StrackTraceFrame *newFrame(ClassInfo *, Function *, const char *);

		// 取出栈顶的帧 (会移除)
		StrackTraceFrame *popFrame();

		// 获得帧数组
		StrackTraceFrameArray frames() const;

	private:

		std::queue<StrackTraceFrame*> m_frames;
	};


}