#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>
#include <stdio.h>
#endif // WIN32

#include <stdlib.h>

#include "../include/Utils.h"

namespace langX {
	static const char * aZ0_str = "qwertyuiopasdfghjklzxcvbnm0123456789QWERTYUIOPASDFGHJKLZXCVBNM";
	static const int aZ0_len = 62 - 1;

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
			return;
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

		for (int i = 8; i < randomLen + 8; i++)
		{
			array[i] = aZ0_str[(rand() % aZ0_len)];
		}

		return;
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

	std::string unescape(const std::string& s)
	{
		std::string res;
		std::string::const_iterator it = s.begin();
		while (it != s.end())
		{
			char c = *it++;
			if (c == '\\' && it != s.end())
			{
				char t = *it++;
				switch (t) {
				case '\\': c = '\\'; break;
				case 'n': c = '\n'; break;
				case 't': c = '\t'; break;
				case 'a': c = '\a'; break;
				case 'b': c = '\b'; break;
					// all other escapes
				default:
					// invalid escape sequence - let it go
					c = t;
					break;
				}
			}
			res += c;
		}

		return res;
	}

	bool endsWith(std::string const &fullString, std::string const &ending) {
		if (fullString.length() >= ending.length()) {
			return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
		}
		else {
			return false;
		}
	}

    void freeDoubleCharArray(char **array, int len) {
        if (len <= 0 || array == nullptr) {
            return;
        }

        for (int i = 0; i < len; ++i) {
            free(array[i]);
        }

        free(array);
    }

    template<typename T, typename>
    T langX::max(T a, T b) {
        return a >= b ? a : b;
    }

    template<typename T, typename>
    T langX::min(T a, T b) {
        return a <= b ? a : b;
    }


    // 模板函数 实例化
    template short max<short >(short a, short b);
    template short min<short >(short a, short b);

    template int max<int >(int a, int b);
    template int min<int >(int a, int b);


    int convertToAbsolutePath(const char * filename, const char *parsingFile, char *result){
        //  把路径转换成绝对路径
        if (filename[0] != '/') {
            //  非绝对路径
            char tmpBuf[1024];

            if (realpath(parsingFile, tmpBuf)) {
                // ok
                std::string a(tmpBuf);
                auto it = a.find_last_of('/');
                if (it != std::string::npos) {
                    // 找到了最后一个 /
                    a = a.substr(0, it + 1);
                    a += filename;
                    sprintf(result, "%s", a.c_str());
                    return 0;
                }
            }
        } else {
            //
            sprintf(result, "%s", filename);
            return 0;
        }

        return 1;
    }

}