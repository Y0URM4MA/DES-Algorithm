#pragma once
#include <string>
class Des {
public:
	static std::string compressKey(const std::string key);
	static std::string leftShift(const std::string str);
	static std::string* cdCreation(std::string key);
	static std::string* mergeKeys(const std::string* c,const std::string* d);
	static std::string* secondPermutaion(const std::string* keys);
	static std::string inintialPermutation(const std::string message);
	static std::string twoStringXor(const std::string a, const std::string b);
	static std::string finalIterations(const std::string left, const std::string right, const std::string* keys);
	static std::string finalPermutation(const std::string str);
	static std::string fullDes(std::string msg, std::string key);
	static std::string* invertKeys(const std::string* keys);
	static std::string fullDecryption(std::string cipher, std::string key);
};