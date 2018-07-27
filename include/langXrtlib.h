#pragma once

/* 
 * @date 2018-7-21 ����
 * @author hideDragon
 *
 * ���ļ������������ڼ������п��һЩ����  
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
	// ��ʼ�� ��������ռ�
	void initRTNameSpace(langXState *);

	// ���� runtime lib 
	void loadRTLib(langXState *);


}