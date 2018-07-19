#pragma once
#include <vector>
#include <string>

namespace langX {

	// ����� 1970��һ��һ�յ����꾭���ĺ�����
	long getTime();

	//  ����һ�����������ֵ
	void randomCharacteristic(char *,int ,void *, int randomLen);

	std::vector<std::string> splitString(const std::string &str, const std::string &pattern);

	// �����ַ����ڵ�ת���ַ�
	std::string unescape(const std::string& s);

}