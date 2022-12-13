#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>


int main() {
  PhoneBook phoneBook;
  std::string command;

  while (true) {
    std::cout << "$> ";
    getline(std::cin, command);
    if (command.compare("EXIT") == 0) {
      std::cout << "Exiting..." << std::endl;
      return 0;
    } else if (command.compare("ADD") == 0) {
      phoneBook.addContact(Contact::fromUserInput());
    } else if (command.compare("SEARCH") == 0) {
      phoneBook.searchContact();
    } else if (command.empty()) {
    } else {
      std::cout << "[" << command << "] is not a valid command" << std::endl;
    }
  }
}
