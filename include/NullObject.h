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

		bool isTrue() const override;
		ObjectType getType() const override;
		Object* clone() const override;
		void update(const Object *) override;

	private:

		void finalize() override;

	};

}