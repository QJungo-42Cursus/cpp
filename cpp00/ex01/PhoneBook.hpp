#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
  unsigned int registered;
  int current_index;

public:
  PhoneBook();
  void addContact(Contact contact);
  void searchContact();
  void displayContacts();
  Contact contacts[8];
};

#endif /* PHONEBOOK_HPP */
