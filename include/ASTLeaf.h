#pragma once
#include "ASTNode.h"

/*
*   ����ʱ�䣺  2016-07-04
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     �����﷨����Ҷ�ӽڵ���
*/

namespace langX {
	/* �����﷨����Ҷ�ӽڵ��� */
	class ASTLeaf : public ASTNode
	{
	public:
		ASTNode* child(int i) const;
	private:

	};


}