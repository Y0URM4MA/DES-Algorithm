#include "DesAlgo.h"
#include <iostream>
#include <string>
#include "Function.h"


std::string Des::compressKey(std::string key) //the first permutation to the key.
{
	std::string compKey{ "" };
	const int pc1[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
	};
	for (int i = 0; i < 56; i++) {
		compKey += key[pc1[i] - 1];
	}
	return compKey;
}

std::string Des::leftShift(std::string str) //function that "rotates the string to the left (left shift)" once.
{
	std::string shifted{ "" };
	for (int i = 1; i < 28; i++) {
		shifted += str[i];
	}
	shifted += str[0];
	return shifted;
}

std::string* Des::cdCreation(std::string key) //this funciton creates the 16 sub keys from the original permuted key after splitting it.
{
	std::string* cd{ new std::string[16] };
	for (int i = 0; i <= 15; i++) {
		if (i == 0 || i == 1 || i == 8 || i == 15) //if it's the first, the second, the ninth or the sixteenth iteration, the sub key needs to do 2 left shifts
			cd[i] = leftShift(key);
		else
		{
			cd[i] = leftShift(key);
			cd[i] = leftShift(cd[i]);
		}
		key = cd[i];
	}
	return cd;
}

std::string* Des::mergeKeys(std::string* c, std::string* d) //merging the two halves of the shifted keys to one 56 bit keys.(C1 and D1 will merge into K1)
{
	std::string* keys{ new std::string[16] };
	for (int i = 0; i < 16; i++)
	{
		keys[i] = c[i] + d[i];
	}
	return keys;
}

std::string* Des::secondPermutaion(std::string* keys) //applying the second permutaion to every subkey, every subkey becomes 48 bit long.
{
	std::string* newKeys{ new std::string[16] };
	int pc2[48] = { 14, 17, 11, 24, 1, 5,
				  3, 28, 15, 6, 21, 10,
				  23, 19, 12, 4, 26, 8,
				  16, 7, 27, 20, 13, 2,
				  41, 52, 31, 37, 47, 55,
				  30, 40, 51, 45, 33, 48,
				  44, 49, 39, 56, 34, 53,
				  46, 42, 50, 36, 29, 32 };
	for (int i = 0; i < 16; i++)
	{
		for (int t = 0; t < 48; t++)
		{
			newKeys[i] += (keys[i])[pc2[t] - 1];
		}
	}

	return newKeys;
}

std::string Des::inintialPermutation(std::string message) //The first permutation to the message we want to decrypt;
{
	int arr[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
					60, 52, 44, 36, 28, 20, 12, 4,
					62, 54, 46, 38, 30, 22, 14, 6,
					64, 56, 48, 40, 32, 24, 16, 8,
					57, 49, 41, 33, 25, 17, 9, 1,
					59, 51, 43, 35, 27, 19, 11, 3,
					61, 53, 45, 37, 29, 21, 13, 5,
					63, 55, 47, 39, 31, 23, 15, 7 };
	std::string ip = "";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		ip += message[arr[i] - 1];
	}
	return ip;
}

std::string Des::twoStringXor(std::string a, std::string b) //"xoring" two string assuming they have the same legnth and they are only zeros and ones.
{
	std::string xored{ "" };
	for (int i = 0; i < a.size(); i++) {
		if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
			xored += "1";
		else
		{
			xored += "0";
		}
	}

	return xored;
}

std::string Des::finalIterations(std::string left, std::string right, std::string* keys)
{
	std::string finalStr{ "" };
	std::string lefts[17]{ left };
	std::string rights[17]{ right };
	for (int i = 1; i <= 16; i++)
	{
		lefts[i] = rights[i - 1];
		rights[i] = Des::twoStringXor(lefts[i - 1], Function::fullFunc(rights[i - 1], keys[i - 1]));
	}
	finalStr += rights[16];
	finalStr += lefts[16];
	return finalStr;
}

std::string Des::finalPermutation(std::string str)
{
	std::string finalStr{ "" };
	int arr[64]{ 40,8,48,16,56,24,64,32,
				 39,7,47,15,55,23,63,31,
				 38,6,46,14,54,22,62,30,
				 37,5,45,13,53,21,61,29,
				 36,4,44,12,52,20,60,28,
				 35,3,43,11,51,19,59,27,
				 34,2,42,10,50,18,58,26,
				 33,1,41,9,49,17,57,25 };
	for (int i = 0; i < 64; i++) {
		finalStr += str[arr[i] - 1];
	}
	return finalStr;
}

std::string Des::fullDes(std::string msg, std::string key) //the final function that does the full encryption.
{
	std::string encrypted{ "" };
	for (int i = 0; i < msg.length(); i += 64) {
		std::string ipm = msg.substr(i, 64);
		std::string kPlus{ Des::compressKey(key) };
		std::string left{ kPlus.substr(0, 28) };
		std::string right{ kPlus.substr(28, 28) };
		std::string* c{ Des::cdCreation(left) };
		std::string* d{ Des::cdCreation(right) };
		std::string* keys{ Des::mergeKeys(c,d) };
		delete[] c;
		delete[] d;
		std::string* pc2Keys{ Des::secondPermutaion(keys) };
		delete[] keys;
		ipm = Des::inintialPermutation(msg);
		std::string mLeft{ ipm.substr(0,32) };
		std::string mRight{ ipm.substr(32,32) };
		std::string str{ Des::finalIterations(mLeft,mRight,pc2Keys) };
		delete[] pc2Keys;
		encrypted += Des::finalPermutation(str);
	}

	return encrypted;
}

std::string* Des::invertKeys(std::string* keys)//function to invert the array in order to use the keys in the opposite way for decryption form K16 to K1.
{
	std::string* newKeys{ new std::string[16] };
	for (int i = 0; i < 16; i++) {
		newKeys[i] = keys[15 - i];
	}
	return newKeys;
}

std::string Des::fullDecryption(std::string cipher, std::string key)
{
	std::string decrypted{ "" };
	for (int i = 0; i < cipher.length(); i += 64) {
		std::string ipm;
		ipm = cipher.substr(i, 64);
		std::string kPlus{ Des::compressKey(key) };
		std::string left{ kPlus.substr(0, 28) };
		std::string right{ kPlus.substr(28, 28) };
		std::string* c{ Des::cdCreation(left) };
		std::string* d{ Des::cdCreation(right) };
		std::string* keys{ Des::mergeKeys(c,d) };
		delete[] c;
		delete[] d;
		std::string* pc2Keys{ Des::secondPermutaion(keys) };
		delete[] keys;
		std::string* newPC2Keys{ Des::invertKeys(pc2Keys) };
		delete[] pc2Keys;
		ipm = Des::inintialPermutation(cipher);
		std::string mLeft{ ipm.substr(0,32) };
		std::string mRight{ ipm.substr(32,32) };
		std::string str{ Des::finalIterations(mLeft,mRight,newPC2Keys) };
		delete[] newPC2Keys;
		decrypted += Des::finalPermutation(str);
	}
	return decrypted;
}


