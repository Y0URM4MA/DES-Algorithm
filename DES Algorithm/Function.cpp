#include "Function.h"
#include "Header.h"

std::string Function::eBit(std::string string)//permuting the R(n-1) and making it 48 bit long from 32 bit length by repeating some bits
{
	std::string s{ "" };
	int arr[48]{ 32, 1, 2, 3, 4, 5,
				 4, 5, 6, 7, 8, 9,
				 8, 9, 10, 11, 12, 13,
				 12, 13, 14, 15, 16, 17,
				 16, 17, 18, 19, 20, 21,
				 20, 21, 22, 23, 24, 25,
				 24, 25, 26, 27, 28, 29,
				 28, 29, 30, 31, 32, 1 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		s += string[arr[i] - 1];
	}
	return s;
}

std::string Function::sBoxes(std::string s)
{
	int subBoxes[8][4][16] =
	{ {
		{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
		{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
		{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
	},
	{
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
	},
	{
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
		{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
		{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
		{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
	},
	{
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
	},
	{
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
	},
	{
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
	},
	{
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
	},
	{
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
	} };
	std::string b[8][2];
	b[0][0] = s.substr(1, 4);
	b[0][1] += s[0];
	b[0][1] += s[5];
	b[1][0] = s.substr(7, 4);
	b[1][1] += s[6];
	b[1][1] += s[11];
	b[2][0] = s.substr(13, 4);
	b[2][1] += s[12];
	b[2][1] += s[17];
	b[3][0] = s.substr(19, 4);
	b[3][1] += s[18];
	b[3][1] += s[23];
	b[4][0] = s.substr(25, 4);
	b[4][1] += s[24];
	b[4][1] += s[29];
	b[5][0] = s.substr(31, 4);
	b[5][1] += s[30];
	b[5][1] += s[35];
	b[6][0] = s.substr(37, 4);
	b[6][1] += s[36];
	b[6][1] += s[41];
	b[7][0] = s.substr(43, 4);
	b[7][1] += s[42];
	b[7][1] += s[47];
	std::string output{ "" };
	for (int i = 0; i < 8; i++) {
		output += intToBinary(subBoxes[i][binaryToInt(b[i][1])][binaryToInt(b[i][0])]);
	}
	return output;
}

int Function::binaryToInt(std::string s)
{
	if (s.compare("00") == 0)
		return 0;
	if (s.compare("01") == 0)
		return 1;
	if (s.compare("10") == 0)
		return 2;
	if (s.compare("11") == 0)
		return 3;
	if (s.compare("0000") == 0)
		return 0;
	if (s.compare("0001") == 0)
		return 1;
	if (s.compare("0010") == 0)
		return 2;
	if (s.compare("0011") == 0)
		return 3;
	if (s.compare("0100") == 0)
		return 4;
	if (s.compare("0101") == 0)
		return 5;
	if (s.compare("0110") == 0)
		return 6;
	if (s.compare("0111") == 0)
		return 7;
	if (s.compare("1000") == 0)
		return 8;
	if (s.compare("1001") == 0)
		return 9;
	if (s.compare("1010") == 0)
		return 10;
	if (s.compare("1011") == 0)
		return 11;
	if (s.compare("1100") == 0)
		return 12;
	if (s.compare("1101") == 0)
		return 13;
	if (s.compare("1110") == 0)
		return 14;
	if (s.compare("1111") == 0)
		return 15;

}

std::string Function::intToBinary(int num)
{
	if (num == 0)
		return "0000";
	if (num == 1)
		return "0001";
	if (num == 2)
		return "0010";
	if (num == 3)
		return "0011";
	if (num == 4)
		return "0100";
	if (num == 5)
		return "0101";
	if (num == 6)
		return "0110";
	if (num == 7)
		return "0111";
	if (num == 8)
		return "1000";
	if (num == 9)
		return "1001";
	if (num == 10)
		return "1010";
	if (num == 11)
		return "1011";
	if (num == 12)
		return "1100";
	if (num == 13)
		return "1101";
	if (num == 14)
		return "1110";
	if (num == 15)
		return "1111";

}

std::string Function::pPermutation(std::string s)
{	
	std::string newString{ "" };
	int arr[32]{ 16, 7, 20, 21,
				 29, 12, 28, 17,
				 1, 15, 23, 26,
				 5, 18, 31, 10,
				 2, 8, 24, 14,
				 32, 27, 3, 9,
				 19, 13, 30, 6,
				 22, 11, 4, 25 };
	for (int i = 0; i < 32; i++) {
		newString += s[arr[i] - 1];
	}
	return newString;
}

std::string Function::fullFunc(std::string s,std::string key) //input is Rn-1 and Kn and it return the combintaion of all functions that makes the F function.
{	
	return Function::pPermutation(Function::sBoxes(Des::twoStringXor(key, Function::eBit(s))));
}

