#pragma once

namespace langX {

	class DefaultNetPacket;

	class BytesEncoder
	{
	public:
		BytesEncoder();
		~BytesEncoder();

		//  ���� �� �ڶ�������Ϊ����
		virtual char * encord(DefaultNetPacket *, int *) = 0;

	private:

	};


}