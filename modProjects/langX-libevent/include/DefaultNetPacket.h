#pragma once

namespace langX {

	class DefaultNetPacket
	{
	public:
		DefaultNetPacket();
		~DefaultNetPacket();
		DefaultNetPacket(char *, int);

		int readInt();
		double readDouble();
		// 传参为 字符串的长度
		const char *readString(int *);

		void writeInt(int);
		void writeDouble(double);
		void writeString(const char *, int);

		int getSize() const;

		int getPos() const;
		void setPos(int);

	private:

		char *m_buffer = nullptr;
		int m_size = 0;
		int m_pos = 0;

	};
}