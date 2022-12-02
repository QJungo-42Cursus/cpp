#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() {

  registered = 0;
  current_index = -1;

  //this.contacts = contacts;

}

void PhoneBook::addContact(Contact contact) {
  current_index++;
  if (current_index == 8)
    current_index = 0;
  contacts[current_index] = contact;
  std::cout << "Contact added (index " << current_index << ")" << std::endl;
  if (registered != 8)
    registered++;
}

void PhoneBook::searchContact() {
  /// Will first display all contacts
  this->displayContacts();

  /// Then ask for the index of the contact to display
  std::cout << "Enter index: ";
  int index;
  std::cin >> index;

  /// Check if the index is valid
  if (index < 0 || index >= registered) {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  /// Finaly print the full contact
  this->contacts[index].full_display(index);
}

void PhoneBook::displayContacts() {
  for (int i = 0; i < 8; i++) {
    if (registered == i)
      break;
    contacts[i].display(i);
  }
}
