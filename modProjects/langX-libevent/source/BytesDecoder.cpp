#include "../include/BytesDecoder.h"

#include "../../../include/Object.h"
#include "../../../include/langXObject.h"

#include <stdlib.h>

namespace langX {



	BytesDecoder::BytesDecoder()
	{
	}

	BytesDecoder::~BytesDecoder()
	{
	}

	langXBytesDecoder::langXBytesDecoder(langXObject * langXObject) : langXBytesDecoder(langXObject, 1 * 1024 * 1024)
	{
	}

	langXBytesDecoder::langXBytesDecoder(langXObject * langXObject, int bufferSize)
	{
		this->m_langXObject = langXObject;
		this->m_pos = 0;
		this->m_bufferSize = 0;

		if (bufferSize > 0)
		{
			this->m_buffer = (char*)calloc(1, bufferSize);
			if (this->m_buffer)
			{
				this->m_bufferSize = bufferSize;
			}
		}
	}

	langXBytesDecoder::~langXBytesDecoder()
	{
		if (this->m_buffer)
		{
			free(this->m_buffer);
		}
	}

	langXObject * langXBytesDecoder::decode(char * buf, int len)
	{


		return nullptr;
	}

}
