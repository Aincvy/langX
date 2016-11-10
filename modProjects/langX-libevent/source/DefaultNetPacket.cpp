#include "../include/DefaultNetPacket.h"

namespace langX {



	DefaultNetPacket::DefaultNetPacket()
	{
	}

	DefaultNetPacket::~DefaultNetPacket()
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

}