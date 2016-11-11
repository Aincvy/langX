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


}