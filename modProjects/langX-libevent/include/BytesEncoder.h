#pragma once

namespace langX {

	class BytesEncoder
	{
	public:
		BytesEncoder();
		virtual ~BytesEncoder();

		//  编码 ， 第二个参数为长度
		virtual char * encord(void *, int *) = 0;

	private:

	};


	// langX 内部的编码器
	class langXBytesEncoder : public BytesEncoder {

	public:
		langXBytesEncoder();
		~langXBytesEncoder();

		char * encord(void *, int *);

	};

}