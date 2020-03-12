#include <iostream>
#include <string>
#include "DesAlgo.h"
#include "Function.h"
#include "UI.h"

int main() {
	while (true) {
		UI::startingMsg();
		int choice;
		std::cout << "\nYour choice: " << std::flush;
		std::cin >> choice;
		if (choice == 1) {
			while (true) {
				std::cout << "Enter the message you want to encrypt: " << std::flush;
				std::string s;
				std::cin >> s;
				if (s.length() % 16 != 0) {
					std::cout << "The message's length isn't correct (must be a multiple of 16)." << std::endl;
					continue;
				}
				std::cout << "Enter the key you want to decrypt with: " << std::flush;
				std::string key;
				std::cin >> key;
				if (key.length() != 16) {
					std::cout << "The length of the key must be exactly 16 characters." << std::endl;
					continue;
				}
				std::cout << "The encrypted message is: " << std::flush;
				std::cout << UI::binaryToHexString(Des::fullDes(UI::HexToBinaryString(s), UI::HexToBinaryString(key))) << std::endl;
				break;
			}

		}
		else if (choice == 2) {
			while (true) {
				std::cout << "Enter the message you want to decrypt: " << std::flush;
				std::string s;
				std::cin >> s;
				if (s.length() % 16 != 0) {
					std::cout << "The message's length isn't correct (must be a multiple of 16)." << std::endl;
					continue;
				}
				std::cout << "Enter the key you want to decrypt with: " << std::flush;
				std::string key;
				std::cin >> key;
				if (key.length() != 16) {
					std::cout << "The length of the key must be exactly 16 characters." << std::endl;
					continue;
				}
				std::cout << "The decrypted message is: " << std::flush;
				std::cout << UI::binaryToHexString(Des::fullDecryption(UI::HexToBinaryString(s), UI::HexToBinaryString(key))) << std::endl;
				break;
			}
		}
		else if (choice == 3) {
			std::cout << "Thanks for using my program, have a great day!" << std::endl;
			break;
		}
		else {
			std::cout << "This is not a valid choice." << std::endl;
			continue;
		}
	}
}
