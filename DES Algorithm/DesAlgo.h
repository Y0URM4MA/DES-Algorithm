#pragma once
#include <string>
class Des {
public:
	static std::string compressKey(std::string key);
	static std::string leftShift(std::string str);
	static std::string* cdCreation(std::string key);
	static std::string* mergeKeys(std::string* c, std::string* d);
	static std::string* secondPermutaion(std::string* keys);
	static std::string inintialPermutation(std::string message);
	static std::string twoStringXor(std::string a, std::string b);
	static std::string finalIterations(std::string left, std::string right, std::string* keys);
	static std::string finalPermutation(std::string str);
	static std::string fullDes(std::string msg, std::string key);
	static std::string* invertKeys(std::string* keys);
	static std::string fullDecryption(std::string cipher, std::string key);
};