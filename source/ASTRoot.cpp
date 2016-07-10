#include "../include/ASTRoot.h"

namespace langX {
	ASTNode * ASTRoot::child(int i) const
	{
		if (i < 0 || i >= m_children.size())
		{
			return nullptr;
		}
		return m_children.at(i);
	}
}