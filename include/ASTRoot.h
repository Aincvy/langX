#pragma once
#include "ASTNode.h"
#include <vector>

/*
*   创建时间：  2016-07-04
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     抽象语法树的根节点类
*/

namespace langX {
	/* 抽象语法树的根节点类 */
	class ASTRoot: ASTNode
	{
	public:
		ASTNode* child(int i) const;
	private:
		std::vector<ASTNode*> m_children;
	};

}