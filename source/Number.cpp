#include <string>
#include <stdio.h>
#include <sstream>

#include "Object.h"
#include "Number.h"

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

	bool Number::isInteger() const {
		return this->m_value == (int)this->m_value;
	}

	const char * Number::characteristic() const
	{
		std::stringstream ss;
		if (this->isInteger())
		{
			ss << getIntValue();
		}
		else {
			ss << this->m_value;
		}

		this->m_characteristic = ss.str();

		return this->m_characteristic.c_str();
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
		obj->setConst(this->isConst());
		obj->setLocal(this->isLocal());
		obj->setName(this->getName());
		return obj;
	}

	void Number::update(const Object *right)
	{
		if (right == nullptr || right->getType() != NUMBER)
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

    long Number::getLongValue() const {
        return (long)this->m_value;
    }

    bool Number::flagBool() const {
        return this->m_flagBool;
    }

    void Number::flagBool(bool flag) {
        this->m_flagBool = flag;
    }

    void Number::setIntValue(int i) {
        setValue(i);
    }

    void Number::setLongValue(long l) {
        setValue( (double ) l );
    }

}