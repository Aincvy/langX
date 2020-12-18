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

		/**
		 * 当前数字 是否是一个 bool 类型得？
		 * 如果当前数字是一个bool 类型， 请使用 isTrue() 函数来判断它得具体值
		 * @return true: 是， false: 不是
		 */
		bool flagBool() const;

		/**
		 * 设置当前数字得 bool flag
		 * @param flag
		 */
		void flagBool(bool flag);

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

		// 当前数字是否是一个 Bool
		bool m_flagBool = false;

		void finalize();

		
	};
}