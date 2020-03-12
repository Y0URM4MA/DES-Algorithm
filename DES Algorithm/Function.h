#pragma once
#include <string>
//Anything related to the F fucntion is programmed in this header's source file,
//just to make things a little bit more organized.

class Function {
public:
	static std::string eBit(const std::string string);
	static std::string sBoxes(const std::string s);
	static int binaryToInt(const std::string s);
	static std::string intToBinary(const int num);
	static std::string pPermutation(const std::string s);
	static std::string fullFunc(const std::string s,const std::string key);
};
