#pragma once
#include <string>
/*
 *   ����ʱ�䣺  2016-07-04  
 *   ���ߣ� The World(world@aincvy.com)
 *   
 *   �ļ�������
 *   ������     �����﷨���Ľڵ� �ӿ�
*/

namespace langX {
	/* �����﷨���Ľڵ� �ӿ� */
	class ASTNode
	{
	public:
		ASTNode(const std::string & value);
		ASTNode(const char * value);
		ASTNode(const char *value, ASTNode * parent);

		/* ���ص�ǰ�ڵ���ַ���ֵ */
		virtual std::string value() const;
		/* ���ڵ� */
		virtual ASTNode* parent() const;
		/* ��ȡĳ���ӽڵ� */
		virtual ASTNode* child(int i) const = 0;

	protected:
		ASTNode * m_parent = nullptr;
		std::string m_value;

	private:
		
	};
	
}