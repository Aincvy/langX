#pragma once
#include <string>
/*
 *   创建时间：  2016-07-04  
 *   作者： The World(world@aincvy.com)
 *   
 *   文件描述：
 *   描述：     抽象语法树的节点 接口
*/

namespace langX {
	/* 抽象语法树的节点 接口 */
	class ASTNode
	{
	public:
		ASTNode(const std::string & value);
		ASTNode(const char * value);
		ASTNode(const char *value, ASTNode * parent);

		/* 返回当前节点的字符串值 */
		virtual std::string value() const;
		/* 父节点 */
		virtual ASTNode* parent() const;
		/* 获取某个子节点 */
		virtual ASTNode* child(int i) const = 0;

	protected:
		ASTNode * m_parent = nullptr;
		std::string m_value;

	private:
		
	};
	
}