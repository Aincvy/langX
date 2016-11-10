#pragma once
#include "BytesDecoder.h"

namespace langX {

	class DefaultBytesDecoder : public BytesDecoder
	{
	public:
		DefaultBytesDecoder();
		~DefaultBytesDecoder();


		void* decode(char *, int);

	private:

	};

}