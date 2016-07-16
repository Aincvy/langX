#pragma once
#include "Object.h"

namespace langX {
	class Number : public Object
	{
	public:
		Number();
		Number(int);
		Number(double);
		~Number();

		// 更新当前对象的值为参数的值 
		void update(double);

		int getIntValue() const;
		double getDoubleValue() const;

		bool isTrue() const;
		ObjectType getType() const;

		operator int() const;
		operator double() const;
		Number operator+ (const Number&);
		Number operator- (const Number&);
		Number operator* (const Number&);
		Number operator/ (const Number&);
		Number operator= (const Number&);
	private:
		double m_value = 0;
	};
}