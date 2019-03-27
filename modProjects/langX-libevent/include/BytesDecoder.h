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


	// ����һ�� langX ������ ������
	class langXBytesDecoder : public BytesDecoder {

	public:

		langXBytesDecoder(langXObject *langXObject);
		langXBytesDecoder(langXObject *langXObject, int bufferSize);
		~langXBytesDecoder();

		//  
		langXObject* decode(char *buf, int len);

	private:
		// �ڲ���һ��СһЩ��buffer
		char *m_buffer;
		int m_pos;
		int m_bufferSize;

		langXObject *m_langXObject;
	};

}