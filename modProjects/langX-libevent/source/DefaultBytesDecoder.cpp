#include "../include/DefaultBytesDecoder.h"
#include "Object.h"
#include "Function.h"
#include "langXObject.h"

namespace langX {



	DefaultBytesDecoder::DefaultBytesDecoder()
	{
	}
	DefaultBytesDecoder::~DefaultBytesDecoder()
	{
	}

	langXObject * DefaultBytesDecoder::decode(char *, int)
	{
		return nullptr;
	}
}