#pragma once

#include "../../../include/langX.h"
#include "../../../include/XNameSpace.h"

#ifdef WIN32
#include "../../../lib/cJSON-1.3.0/cJSON.h"
#else
#include <cjson/cJSON.h>
#endif

namespace langX {

	class langXObject;

	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

	// ����Ϊ ���jsonobj �ĸ��� �������null ����Զ�����һ��
	langXObject * createJsonObject(cJSON *);
	// ����Ϊ ���jsonarray �ĸ��� �������null ����Զ�����һ��
	langXObject * createJsonArray(cJSON *);
	
	// һЩ���ݽṹ

	//  json ���ݵı���
	struct MyJsonData
	{
		cJSON * pJsonRoot;
	};

}