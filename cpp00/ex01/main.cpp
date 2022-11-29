#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <bits/stdc++.h>
#include <iostream>

int main() {
  PhoneBook phoneBook;
  std::string command;

  while (true) {
    std::cout << "$> ";
    std::cin >> command;
    if (command.compare("EXIT") == 0) {
      // free ? TODO
      return 0;
    } else if (command.compare("ADD") == 0) {
      Contact contact = Contact::fromUserInput();
      phoneBook.addContact(contact);
      std::cout << "Contact added" << std::endl;
    } else if (command.compare("SEARCH") == 0) {
      phoneBook.searchContact();
    }
  }
}
