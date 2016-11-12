#pragma once

namespace langX {

	class langXObject;

	class BytesDecoder
	{
	public:
		BytesDecoder();
		virtual ~BytesDecoder();

		//
		virtual langXObject* decode(char *, int) = 0;

	private:

	};

}