#pragma once
#include "BytesEncoder.h"

namespace langX {

	class DefaultBytesEncoder : BytesEncoder
	{
	public:
		DefaultBytesEncoder();
		~DefaultBytesEncoder();

		char * encord(DefaultNetPacket *, int *);

	private:

	};


}
