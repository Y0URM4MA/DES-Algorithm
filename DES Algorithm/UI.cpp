#include "UI.h"
#include <bitset>
#include <iostream>
#include<string>


std::string UI::binaryToHexString(std::string bs)
{
	std::string char4;
	std::string output{ "" };
	for (int i = 0; i < bs.length(); i += 4) {
		char4 = bs.substr(i, 4);
		if (char4.compare("0000") == 0) {
			output += "0";
		}
		else if (char4.compare("0001") == 0) {
			output += "1";
		}
		else if (char4.compare("0010") == 0) {
			output += "2";
		}
		else if (char4.compare("0011") == 0) {
			output += "3";
		}
		else if (char4.compare("0100") == 0) {
			output += "4";
		}
		else if (char4.compare("0101") == 0) {
			output += "5";
		}
		else if (char4.compare("0110") == 0) {
			output += "6";
		}
		else if (char4.compare("0111") == 0) {
			output += "7";
		}
		else if (char4.compare("1000") == 0) {
			output += "8";
		}
		else if (char4.compare("1001") == 0) {
			output += "9";
		}
		else if (char4.compare("1010") == 0) {
			output += "A";
		}
		else if (char4.compare("1011") == 0) {
			output += "B";
		}
		else if (char4.compare("1100") == 0) {
			output += "C";
		}
		else if (char4.compare("1101") == 0) {
			output += "D";
		}
		else if (char4.compare("1110") == 0) {
			output += "E";
		}
		else {
			output += "F";
		}
	}
	return output;
}

std::string UI::HexToBinaryString(std::string hs)
{
	std::string output{ "" };
	std::string tmp;
	for (int i = 0; i < hs.length();i++) {
		tmp = hs[i];
		if (tmp.compare("0")==0) {
			output += "0000";
		}
		else if (tmp.compare("1") == 0) {
			output += "0001";
		}
		else if (tmp.compare("2") == 0) {
			output += "0010";
		}
		else if (tmp.compare("3") == 0) {
			output += "0011";
		}
		else if (tmp.compare("4") == 0) {
			output += "0100";
		}
		else if (tmp.compare("5") == 0) {
			output += "0101";
		}
		else if (tmp.compare("6") == 0) {
			output += "0110";
		}
		else if (tmp.compare("7") == 0) {
			output += "0111";
		}
		else if (tmp.compare("8") == 0) {
			output += "1000";
		}
		else if (tmp.compare("9") == 0) {
			output += "1001";
		}
		else if (tmp.compare("A") == 0) {
			output += "1010";
		}
		else if (tmp.compare("B") == 0) {
			output += "1011";
		}
		else if (tmp.compare("C") == 0) {
			output += "1100";
		}
		else if (tmp.compare("D") == 0) {
			output += "1101";
		}
		else if (tmp.compare("E") == 0) {
			output += "1110";
		}
		else {
			output += "1111";
		}
	}
	return output;

}


void UI::startingMsg()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "             Welcome to the DES program\n" << std::endl;
	std::cout << "please make sure you use only the numbers 0-9 and the letters A-F (make sure the letters are \"upper cased\")\n"<<std::endl;
	std::cout << "please choose an option:\n\n1) Encryption\n2) Decryption\n3) Exit" << std::endl;
	

}

