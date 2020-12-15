#pragma once
#include <string>
#include <vector>

/*
 * date: 2016-08-22  ,filename: StackTrace.h
 * author:  hideDragon
 * desc:  堆栈跟踪
 */

namespace langX {

	class ClassInfo;
	class Function;

	// 堆栈跟踪的一帧
	class StackTraceFrame
	{
	public:
		StackTraceFrame();
		~StackTraceFrame();

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
		mutable std::string m_info;

		ClassInfo * m_class_info = nullptr;
		Function *m_function = nullptr;

	};

	struct StrackTraceFrameArray
	{
		const StackTraceFrame ** frame;
		int length;
	};

	// 堆栈跟踪
	class StackTrace
	{
	public:
		StackTrace();
		~StackTrace();


        //  生成一个新的帧
        StackTraceFrame *newFrame(Function *, const char *);
		//  生成一个新的帧
		StackTraceFrame *newFrame(ClassInfo *, Function *, const char *);

		// 取出栈顶的帧 (会移除)
		void popFrame();

		StackTraceFrame *top() const;

		// 获得帧数组.  帧数组内的 frames 需要在使用后用 free 函数进行释放
		StrackTraceFrameArray frames() const;

	private:

		std::vector<StackTraceFrame*> m_frames;
	};


}