#pragma once

namespace langX {

	class DefaultNetPacket;

	class BytesEncoder
	{
	public:
		BytesEncoder();
		~BytesEncoder();

		//  编码 ， 第二个参数为长度
		virtual char * encord(DefaultNetPacket *, int *) = 0;

	private:

	};


}