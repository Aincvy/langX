#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>  
#include <stdio.h>
#endif // WIN32

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/Utils.h"


namespace langX {

	static const char * aZ0_str = "qwertyuiopasdfghjklzxcvbnm0123456789QWERTYUIOPASDFGHJKLZXCVBNM";
	static const int aZ0_len = 62 - 1 ;

	long getTime()
	{
#ifdef WIN32

		return -1;
#else
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return (long)((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
#endif // WIN32
		
	}

	void randomCharacteristic(char *array, int arrayLen, void *p, int randomLen)
	{
		if (!p || !array)
		{
			return ;
		}

		memset(array, 0, arrayLen);
		sprintf(array, "%p", p);
		int len = strlen(array);
		if (len < 8)
		{
			// 补齐
			for (int i = len; i < 8; i++)
			{
				array[i] = '0';
			}
		}

		for (int i = 8; i < randomLen+8; i++)
		{
			array[i] = aZ0_str[(rand() % aZ0_len)];
		}

		return ;
	}

	std::vector<std::string> splitString(const std::string & str, const std::string & pattern)
	{
		std::vector<std::string> resVec;

		if ("" == str)
		{
			return resVec;
		}
		//方便截取最后一段数据
		std::string strs = str + pattern;

		size_t pos = strs.find(pattern);
		size_t size = strs.size();

		while (pos != std::string::npos)
		{
			std::string x = strs.substr(0, pos);
			resVec.push_back(x);
			strs = strs.substr(pos + 1, size);
			pos = strs.find(pattern);
		}

		return resVec;
	}

}