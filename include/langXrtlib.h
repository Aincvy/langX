#pragma once

/*
 * @date 2018-7-21 创建
 * @author hideDragon
 *
 * 本文件的内容是用于加载运行库的一些内容
 * rt =  runtime.
 *
 */

#include "XNameSpace.h"

namespace langX {

	class XrtNameSpace : public XNameSpace
	{
	public:
		XrtNameSpace(const char *);
		~XrtNameSpace();

	private:

	};

	class langXState;
	// 初始化 这个命名空间
	void initRTNameSpace(langXState *);

	// 加载 runtime lib
	void loadRTLib(langXState *);


}
