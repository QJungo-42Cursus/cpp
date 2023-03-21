#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>


int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "$> ";
		std::getline(std::cin, command);
		if (std::cin.bad()) {
			std::cout << "IO error, exiting..." << std::endl;
			return 1;
		} else if (std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			return 0;
		}
		if (command.empty()) {
			continue ;
		}
		if (command.compare("EXIT") == 0) {
			std::cout << "Exiting..." << std::endl;
			return 0;
		} else if (command.compare("ADD") == 0) {
			phoneBook.addContact(Contact::fromUserInput());
		} else if (command.compare("SEARCH") == 0) {
			phoneBook.searchContact();
		} else {
			std::cout << "[" << command << "] is not a valid command" << std::endl;
		}
	}
}
