#pragma once
#include <string>
//Anything related to the F fucntion is programmed in this header's source file,
//just to make things a little bit more organized.

class Function {
public:
	static std::string eBit(std::string string);
	static std::string sBoxes(std::string s);
	static int binaryToInt(std::string s);
	static std::string intToBinary(int num);
	static std::string pPermutation(std::string s);
	static std::string fullFunc(std::string s,std::string key);
};
