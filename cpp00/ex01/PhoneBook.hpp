#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
  int registered;
  int current_index;

public:
  PhoneBook();
  //PhoneBook() : arr ( arrData ) {}
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
