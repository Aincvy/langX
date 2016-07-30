#pragma once
#include "Object.h"
#include "Number.h"

namespace langX {
	class Allocator
	{
	public:
		Allocator();
		~Allocator();

		Object *copy(Object *) const;

		Object *allocate(ObjectType) const;
		void free(Object *) const;

		Number *allocateNumber() const;
		Number *allocateNumber(double ) const;
		void freeNumber(Number *);

	private:

	};

}