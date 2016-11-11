#pragma once

namespace langX {


	class BytesDecoder
	{
	public:
		BytesDecoder();
		virtual ~BytesDecoder();

		//
		virtual void* decode(char *, int) = 0;

	private:

	};

}