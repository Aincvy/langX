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


	// 这是一个 langX 函数的 解码器
	class langXBytesDecoder : public BytesDecoder {

	public:

		langXBytesDecoder(langXObject *langXObject);
		langXBytesDecoder(langXObject *langXObject, int bufferSize);
		~langXBytesDecoder();

		//
		langXObject* decode(char *buf, int len);

	private:
		// 内部放一个小一些的buffer
		char *m_buffer;
		int m_pos;
		int m_bufferSize;

		langXObject *m_langXObject;
	};

}
