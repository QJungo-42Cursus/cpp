#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
  int registered = 0;
  int current_index = 0;

public:
  PhoneBook();
  void addContact(Contact contact);
  void searchContact();
  void displayContacts();
  Contact contacts[8] = {
      Contact("", "", "", "", ""), Contact("", "", "", "", ""),
      Contact("", "", "", "", ""), Contact("", "", "", "", ""),
      Contact("", "", "", "", ""), Contact("", "", "", "", ""),
      Contact("", "", "", "", ""), Contact("", "", "", "", "")};
};

#endif /* PHONEBOOK_HPP */
