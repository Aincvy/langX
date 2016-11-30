#include <string>
#include "../include/Object.h"
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
		//printf("~Number\n");
	}

	void Number::update(double a)
	{
		this->m_value = a;
	}

	bool Number::isInteger() {
		return this->m_value == (int) this->m_value;
	}

	int Number::getIntValue() const
	{
		return (int)this->m_value;
	}

	double Number::getDoubleValue() const
	{
		return this->m_value;
	}

	void Number::setValue(double a) 
	{
		this->m_value = a;
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
	Object * Number::clone() const
	{
		Number *obj = new Number(this->m_value);
		obj->setEmergeEnv(getEmergeEnv());
		obj->setCharacteristic(characteristic());
		return obj;
	}
	void Number::update(Object *right)
	{
		if (right == NULL || right->getType() != NUMBER)
		{
			return;
		}
		
		this->m_value = ((Number*)right)->getDoubleValue();
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
	void Number::finalize()
	{
		delete this;
	}
}