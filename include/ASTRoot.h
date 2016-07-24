#pragma once
#include "ASTNode.h"
#include <vector>

/*
*   ����ʱ�䣺  2016-07-04
*   ���ߣ� The World(world@aincvy.com)
*
*   �ļ�������
*   ������     �����﷨���ĸ��ڵ���
*/

namespace langX {
	/* �����﷨���ĸ��ڵ��� */
	class ASTRoot: ASTNode
	{
	public:
		ASTNode* child(int i) const;
	private:
		std::vector<ASTNode*> m_children;
	};

}