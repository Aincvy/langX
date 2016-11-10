#pragma once

namespace langX {

	class DefaultNetPacket
	{
	public:
		DefaultNetPacket();
		~DefaultNetPacket();

		int readInt();
		double readDouble();
		// 传参为 字符串的长度
		const char *readString(int *);

		void writeInt(int);
		void writeDouble(double);
		void writeString(const char *, int);

	private:

	};
}