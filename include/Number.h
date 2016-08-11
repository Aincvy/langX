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

		// ���µ�ǰ�����ֵΪ������ֵ 
		void update(double);

		int getIntValue() const;
		double getDoubleValue() const;

		bool isTrue() const;
		ObjectType getType() const;
		Object* clone() const;
		void update(Object *);

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