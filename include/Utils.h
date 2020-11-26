#pragma once

#include <vector>
#include <string>

namespace langX {

    // 获得自 1970年一月一日到今年经过的毫秒数
    long getTime();

    //  生成一个随机的特性值
    void randomCharacteristic(char *, int, void *, int randomLen);

    std::vector<std::string> splitString(const std::string &str, const std::string &pattern);

    // 处理字符串内的转义字符
    std::string unescape(const std::string &s);

    // 判定一个字符串是否是另外一个的结尾
    bool endsWith(std::string const &fullString, std::string const &ending);

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

}
