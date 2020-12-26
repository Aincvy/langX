#pragma once

#include <vector>
#include <string>

namespace langX {

    // 获得自 1970年一月一日到今年经过的毫秒数
    long getTime();

    //  生成一个随机的特性值
    void randomCharacteristic(char *, int, void *, int randomLen);

    std::vector<std::string> splitString(const std::string &str, const std::string &pattern);

    // 判定一个字符串是否是另外一个的结尾
    bool endsWith(std::string const &fullString, std::string const &ending);

    /**
     * 处理转义字符   |   从 src 转义到 dst 里面
     * @param src    包含带有 \a \b 之类字符串得 字符串
     * @param dst    会转义上述得字符
     * @return 0 表示成功， 1表示有问题
     */
    int workEscapeStr(const char *src, char *dst, size_t srcLen);

    /**
     * 释放一个 char ** 类型的占用内存
     * @param len  外层数组的长度
     */
    void freeDoubleCharArray(char **, int len);

    /**
     * 返回 a 和 b 中较大的那个数字， 一样则返回a
     * @param a
     * @param b
     * @return
     */
    template<
            typename T, //real type
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    T max(T a, T b);

    /**
     * 返回 a 和 b中 较小的那个数字， 一样则返回a
     * @param a
     * @param b
     * @return
     */
    template<
            typename T, //real type
            typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
    >
    T min(T a, T b);


    /**
     * 转换路径成  绝对路径
     * @param filename  文件名
     * @param parsingFile 当前 langX State正在执行的文件路径
     * @param result   转换出来的结果的存放地方
     * @return 1 表示失败  0表示成功
     */
    int convertToAbsolutePath(const char * filename, const char *parsingFile, char *result);

    /**
     * 判断一个字符串是否为 nullptr 或者空字符串
     * @param str
     * @return  true: 是的, false: 不是
     */
    bool isEmpty(const char * str);

}
