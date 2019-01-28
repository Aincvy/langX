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
	class Object;
	class XArray;

	int regJsonArray(langXState *state, XNameSpace* space);

	int regJsonObject(langXState *state, XNameSpace* space);

	// ����Ϊ ���jsonobj �ĸ��� �������null ����Զ�����һ��
	langXObject * createJsonObject(cJSON *);
	// ����Ϊ ���jsonarray �ĸ��� �������null ����Զ�����һ��
	langXObject * createJsonArray(cJSON *);
	
	// ���Ԫ�ص�������
	Object* jsonAddItemToObject(cJSON *, const char *, Object *);
	// ���Ԫ�ص�������
	Object* jsonAddItemToArray(cJSON *, Object *);
	// ��һ��json ���������һ������ !!!  �˺�����δʵ��
	void jsonDecodeToObj(cJSON *, Object *);
	// ��json ������һ������  !!!  �˺�����δʵ��
	void jsonDecodeToArr(cJSON *, XArray *);
	// ������json �����ֵ�� ��Ҫ�����������ʹ�á� 
	// �˺���ֻ���� string/number
	Object* getSimpleJsonValue(cJSON *);

	// json ת��langX����Ĵ��벿��
	Object *cJsonToLangXObject(cJSON *root, langXState *state);
	Object * cJsonToLangXObject_obj(cJSON *root, ClassInfo *empty);
	Object * cJsonToLangXObject_array(cJSON *root, ClassInfo *empty);

	// һЩ���ݽṹ

	//  json ���ݵı���
	struct MyJsonData
	{
		cJSON * pJsonRoot;
	};

}