#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

// PhoneBook constructor
PhoneBook::PhoneBook() {}

void PhoneBook::addContact(Contact contact) {
  this->contacts[this->current_index] = contact;
  this->current_index++;
  if (this->current_index == 8)
    this->current_index = 0;
}

void PhoneBook::searchContact() {
  this->displayContacts();
  std::cout << "Enter index: ";
  int index;
  std::cin >> index;
  this->contacts[index].full_display(index);
}

void PhoneBook::displayContacts() {
  std::cout << "DISPLAY CONTACTS" << std::endl;
  //exit(0);
  int i;
  while (i < 8) {
    this->contacts[i].display(i);
    i++;
  }
}
