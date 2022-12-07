#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

/* Constructor */
PhoneBook::PhoneBook() : registered(0), current_index(-1) {}

/* addContact Method */
void PhoneBook::addContact(Contact contact) {
  current_index++;
  if (current_index == 8)
    current_index = 0;
  contacts[current_index] = contact;
  std::cout << "Contact added (index " << current_index << ")" << std::endl;
  if (registered != 8)
    registered++;
}

/* Display Methods */
void PhoneBook::displayContacts() {
  for (int i = 0; i < 8 && registered != i; i++)
    contacts[i].display(i);
}

/* searchContact Method */
void PhoneBook::searchContact() {
  /// Check if there are contacts
  if (current_index == -1) {
    std::cout << "No contacts to display" << std::endl;
    return;
  }

  /// Will first display all contacts
  this->displayContacts();

  /// Then ask for the index of the contact to display
  unsigned int index;
  while (true) {
    std::cout << "Enter index: ";
    std::string index_input;
    std::getline(std::cin, index_input);

    try {
      index = std::stoi(index_input); // TODO avec sanitizer il ne compile pas
    } catch (std::invalid_argument &e) {
      std::cout << "Invalid index" << std::endl;
      continue;
    }

    if (index >= registered) {
      std::cout << "Invalid index" << std::endl;
    } else {
      break;
    }
  }

  /// Finaly print the full contact
  this->contacts[index].full_display(index);
}
