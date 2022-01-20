#ifdef WIN32
#include <time.h>
#else

#include <sys/time.h>
#include <stdio.h>

#endif // WIN32

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Utils.h"

namespace langX {

    static const char *aZ0_str = "qwertyuiopasdfghjklzxcvbnm0123456789QWERTYUIOPASDFGHJKLZXCVBNM";
    static const int aZ0_len = 62 - 1;

    long getTime() {
#ifdef WIN32

        return -1;
#else
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (long) ((long long) tv.tv_sec * 1000 + tv.tv_usec / 1000);
#endif // WIN32
    }

    void randomCharacteristic(char *array, int arrayLen, void *p, int randomLen) {
        if (!p || !array) {
            return;
        }

        memset(array, 0, arrayLen);
        sprintf(array, "%p", p);
        int len = strlen(array);
        if (len < 8) {
            // 补齐
            for (int i = len; i < 8; i++) {
                array[i] = '0';
            }
        }

        for (int i = 8; i < randomLen + 8; i++) {
            array[i] = aZ0_str[(rand() % aZ0_len)];
        }

        return;
    }

    std::vector<std::string> splitString(const std::string &str, const std::string &pattern) {
        std::vector<std::string> resVec;

        if ("" == str) {
            return resVec;
        }
        //方便截取最后一段数据
        std::string strs = str + pattern;

        size_t pos = strs.find(pattern);
        size_t size = strs.size();

        while (pos != std::string::npos) {
            std::string x = strs.substr(0, pos);
            resVec.push_back(x);
            strs = strs.substr(pos + 1, size);
            pos = strs.find(pattern);
        }

        return resVec;
    }

    /**
     * 从 src 转义到 dst 里面
     * @param src
     * @param dst
     * @return
     */
    int workEscapeStr(const char *src, char *dst, size_t srcLen) {
        // auto size = strlen(src);

        char prev = '\0';
        for (int i = 0, j = 0; i < srcLen; i++, j++) {
            char t = *src++;

            if (prev == '\\') {
                switch (t) {
                    case 'a':
                        dst[j] = '\a';
                        break;
                    case 'b':
                        dst[j] = '\b';
                        break;
                    case 'f':
                        dst[j] = '\f';
                        break;
                    case 'n':
                        dst[j] = '\n';
                        break;
                    case 'r':
                        dst[j] = '\r';
                        break;
                    case 't':
                        dst[j] = '\t';
                        break;
                    case 'v':
                        dst[j] = '\v';
                        break;
                    case '\\':
                    case '\"':
                    case '\'':
                        dst[j] = t;
                        break;
                    case 'x': {
                        //  十六进制 表示得字符串， 大概是 \x00  得形式， 两位
                        char tmpNumberString[3] = {0};

                        for (int a = 0; a < 2 && i < srcLen; a++){
                            i++;
                            t = *src++;

                            if (!isxdigit(t)){
                                if (a == 0) {
                                    // 首个字符就大于F， 说明有问题 \xG  这种字符串肯定是错误得
                                    // 应该报个错， 但是我先忽略把
                                } else {
                                    // 应该是  \xF 类似得格式， 这里回退字符串
                                    src--, i--;
                                }
                                break;
                            } else{
                                tmpNumberString[a] = t;
                            }
                        }

                        int tmpNumber = std::stoi(tmpNumberString, 0, 16);
                        dst[j] = (char)tmpNumber;
                        break;
                    }
                    case 'u':
                        // todo unicode
                        break;
                    default:{
                        if (isdigit(t)) {
                            // 也许是 \000 得数字形式

                            // 把后续得符合格式得字符串全部读取出来
                            char tmpNumberString[4] = {0};
                            tmpNumberString[0] = t;
                            for (int a = 0; a < 2 && i < srcLen; a++){
                                i++;
                                t = *src++;
                                if (isdigit(t)) {
                                    tmpNumberString[a+1] = t;
                                }else {
                                    // 非数字， 回退字符串
                                    src--, i--;
                                    break;
                                }
                            }

                            int tmpNumber = std::stoi(tmpNumberString, 0, 8);
                            dst[j] = (char)tmpNumber;
                        }

                        // maybe need throw error ..
                        break;
                    }
                }
            } else if ( t != '\\'){
                dst[j] = t;
            } else {
                // t is '\' ,but prev not..
                // 调整 dst 得索引， 忽略 \a \b 中得 \ 字符
                j--;
            }

            prev = t;
        }

        return 0;
    }


    bool endsWith(std::string const &fullString, std::string const &ending) {
        if (fullString.length() >= ending.length()) {
            return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
        } else {
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
    T max(T a, T b) {
        return a >= b ? a : b;
    }

    template<typename T, typename>
    T min(T a, T b) {
        return a <= b ? a : b;
    }


    // 模板函数 实例化
    template short max<short>(short a, short b);

    template short min<short>(short a, short b);

    template int max<int>(int a, int b);

    template int min<int>(int a, int b);


    int convertToAbsolutePath(const char *filename, const char *parsingFile, char *result) {
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

    bool isEmpty(const char *str) {
        return str == nullptr || strlen(str) == 0;
    }

}
