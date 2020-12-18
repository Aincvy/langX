#pragma once

#include "X3rdModule.h"
#include "langX.h"

namespace langX {

	class JsonModule : public X3rdModule
	{
	public:
		JsonModule();
		~JsonModule();


		// ��ʼ�� jsonģ��
		int init(langXState *);

		// ж�� jsonģ��
		int unload(langXState *);

	private:

	};


}

