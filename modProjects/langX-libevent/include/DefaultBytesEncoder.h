#pragma once
#include "BytesEncoder.h"

namespace langX {

	class DefaultBytesEncoder : public BytesEncoder
	{
	public:
		DefaultBytesEncoder();
		~DefaultBytesEncoder();

		char * encode(void *, int *);

	private:

	};


}
