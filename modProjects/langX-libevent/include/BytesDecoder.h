#pragma once

namespace langX {

	class DefaultNetPacket;

	class BytesDecoder
	{
	public:
		BytesDecoder();
		~BytesDecoder();

		//
		virtual DefaultNetPacket* decode(char *, int) = 0;

	private:

	};

}