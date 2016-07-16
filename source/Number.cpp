#include "../include/Number.h"
#include <stdio.h>

namespace langX {
	Number::Number()
	{
	}
	Number::Number(int v)
	{
		this->m_value = v;
	}

	Number::Number(double v)
	{
		this->m_value = v;
	}

	Number::~Number()
	{
		printf("~Number");
	}

	void Number::update(double a)
	{
		this->m_value = a;
	}

	int Number::getIntValue() const
	{
		return (int)this->m_value;
	}

	double Number::getDoubleValue() const
	{
		return this->m_value;
	}

	bool Number::isTrue() const
	{
		if (this->m_value == (double)0)
		{
			return false;
		}
		return true;
	}

	ObjectType Number::getType() const
	{
		return NUMBER;
	}
	Number::operator int() const
	{
		return (int)this->m_value;
	}
	Number::operator double() const
	{
		return this->m_value;
	}
	Number Number::operator+(const Number &right)
	{
		this->m_value += right.getDoubleValue();
		return *this;
	}
	Number Number::operator-(const Number &right)
	{
		this->m_value -= right.getDoubleValue();
		return *this;
	}
	Number Number::operator*(const Number &right)
	{
		this->m_value *= right.getDoubleValue();
		return *this;
	}
	Number Number::operator/(const Number &right)
	{
		this->m_value /= right.getDoubleValue();
		return *this;
	}
	Number Number::operator=(const Number &right)
	{
		this->m_value = right.getDoubleValue();
		return *this;
	}
}