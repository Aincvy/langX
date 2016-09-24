#pragma once

namespace langX {
	class Object;
	enum ObjectType;
	class Number;
	class String;
	class FunctionRef;
	class Function;

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

		String *allocateString() const;
		String *allocateString(const char *) const;
		void freeString(String *);

		FunctionRef *allocateFunctionRef(Function *) const;
		void freeFunctionRef(FunctionRef *) const;

	private:

	};

}