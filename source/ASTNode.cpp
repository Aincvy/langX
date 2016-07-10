#include "../include/ASTNode.h"

namespace langX {
	ASTNode::ASTNode(const std::string & value)
	{
		this->m_value = std::string(value);
	}
	ASTNode::ASTNode(const char * value)
	{
		this->m_value = std::string(value);
	}
	ASTNode::ASTNode(const char * value, ASTNode * parent)
	{
		this->m_value = std::string(value);
		this->m_parent = parent;
	}
	std::string ASTNode::value() const
	{
		return (this->m_value);
	}
	ASTNode * ASTNode::parent() const
	{
		return this->m_parent;
	}
}

