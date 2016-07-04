#include "..\include\Token.h"

namespace langX {
	Token::Token(int line_number)
	{
		this->m_line_number = line_number;
	}
	Token::~Token()
	{
	}
	int Token::getLineNumber() const
	{
		return m_line_number;
	}
	bool langX::Token::isNumber() const
	{
		return false;
	}

	bool Token::isString() const
	{
		return false;
	}

	bool Token::isIdentifier() const
	{
		return false;
	}

	std::string Token::getText() const
	{
		return (m_text);
	}

}