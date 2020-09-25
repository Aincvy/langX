#pragma once
#include <vector>
#include <string>

namespace langX {

	// 获得自 1970年一月一日到今年经过的毫秒数
	long getTime();

	//  生成一个随机的特性值
	void randomCharacteristic(char *,int ,void *, int randomLen);

	std::vector<std::string> splitString(const std::string &str, const std::string &pattern);

	// 处理字符串内的转义字符
	std::string unescape(const std::string& s);

	// 判定一个字符串是否是另外一个的结尾
	bool endsWith(std::string const &fullString, std::string const &ending);

}
