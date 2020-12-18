#pragma once

#include "TypeHelper.h"

namespace langX {
	class Object;
	
	// 空引用 对象
	class NullObject : public Object
	{
	public:
		NullObject();
		~NullObject();

		bool isTrue() const;
		ObjectType getType() const;
		Object* clone() const;
		void update(Object *);

	private:

		void finalize();

	};

}