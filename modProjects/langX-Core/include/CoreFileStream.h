#pragma once

#include <fstream>

//  core FileStream 类 相关的东西
namespace langX {

	class langXObject;

	struct CoreFileStream
	{
		std::fstream cppFStream;

	};


	// 参数为path
	CoreFileStream* createCoreFileStream(const char *);

	CoreFileStream* createCoreFileStream();

	void freeCoreFileStream(CoreFileStream *);

	// 参数为path
	langXObject* createFileStreamObj(const char *);


	langXObject* createFileStreamObj(CoreFileStream *);

}