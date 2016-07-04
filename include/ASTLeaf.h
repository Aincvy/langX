#pragma once
#include "ASTNode.h"

/*
*   创建时间：  2016-07-04
*   作者： The World(world@aincvy.com)
*
*   文件描述：
*   描述：     抽象语法树的叶子节点类
*/

namespace langX {
	/* 抽象语法树的叶子节点类 */
	class ASTLeaf : public ASTNode
	{
	public:
		ASTNode* child(int i) const;
	private:

	};


}