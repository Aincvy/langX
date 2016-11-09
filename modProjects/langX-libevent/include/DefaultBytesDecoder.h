#pragma once
#include "BytesDecoder.h"

namespace langX {

	class DefaultBytesDecoder : public BytesDecoder
	{
	public:
		DefaultBytesDecoder();
		~DefaultBytesDecoder();


		DefaultNetPacket* decode(char *, int);

	private:

	};

}