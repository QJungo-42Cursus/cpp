#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
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
  for (unsigned int i = 0; i < 8 && registered != i; i++)
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
  long index;
  while (true) {
    std::cout << "Enter index: ";
    std::string index_input;
    std::getline(std::cin, index_input);

    // if the first is not a number, it will return false
    if (index_input[0] < '0' || index_input[0] > '9') {
      std::cout << "Invalid index" << std::endl;
      continue;
    }

    try {
      std::istringstream(index_input) >> index;
      std::cout << "index: " << index << std::endl;
      if (index < 0)
        throw std::invalid_argument("Invalid index");
    } catch (std::exception &e) {
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
