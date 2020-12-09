#pragma once

namespace langX {
	class Object;

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
		long getLongValue() const;

		void setValue(double);

		bool isTrue() const;
		ObjectType getType() const;
		Object* clone() const;
		void update(Object *);

		// 判断当前值是否是一个int , 判断方式比较简单
		bool isInteger() const;

		const char * characteristic() const;

		operator int() const;
		operator double() const;
		Number operator+ (const Number&);
		Number operator- (const Number&);
		Number operator* (const Number&);
		Number operator/ (const Number&);
		Number operator= (const Number&);
	private:
		double m_value = 0;

		void finalize();

		
	};
}