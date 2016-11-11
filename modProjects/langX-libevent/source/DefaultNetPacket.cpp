#include "../include/DefaultNetPacket.h"

namespace langX {



	DefaultNetPacket::DefaultNetPacket()
	{
	}

	DefaultNetPacket::~DefaultNetPacket()
	{
	}

	DefaultNetPacket::DefaultNetPacket(char *buf, int size)
	{
	}

	int DefaultNetPacket::readInt()
	{
		return 0;
	}

	double DefaultNetPacket::readDouble()
	{
		return 0.0;
	}

	const char * DefaultNetPacket::readString(int *)
	{
		return nullptr;
	}

	void DefaultNetPacket::writeInt(int)
	{
	}

	void DefaultNetPacket::writeDouble(double)
	{
	}

	void DefaultNetPacket::writeString(const char *, int)
	{
	}

	int DefaultNetPacket::getSize() const
	{
		return this->m_size;
	}

	int DefaultNetPacket::getPos() const
	{
		return this->m_pos;
	}

	void DefaultNetPacket::setPos(int a)
	{
		this->m_pos = a;
	}

}