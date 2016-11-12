#pragma once
#include "BytesDecoder.h"

namespace langX {

	class DefaultBytesDecoder : public BytesDecoder
	{
	public:
		DefaultBytesDecoder();
		~DefaultBytesDecoder();


		langXObject* decode(char *, int);

	private:

	};

}