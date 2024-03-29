#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/* Constructor */
Contact::Contact()
    : firstname(""), lastname(""), nickname(""), phone(0), darkest_secret("") {}

/* Display Methods */
static void print_field(std::string field) {
  if (field.length() > 9) {
    std::cout << field.substr(0, 9) << ".";
  } else {
    std::cout << std::setw(10) << field;
  }
  std::cout << "|";
}

void Contact::display(int index) const {
  std::cout << std::right << std::setw(10) << index << "|";
  print_field(firstname);
  print_field(lastname);
  print_field(nickname);
  std::cout << std::endl;
}

void Contact::full_display(int index) const {
  std::cout << index << std::endl;
  std::cout << firstname << std::endl;
  std::cout << lastname << std::endl;
  std::cout << nickname << std::endl;
  std::cout << phone << std::endl;
  std::cout << darkest_secret << std::endl;
}

/* Input Methods */
static void get_input(std::string &to_fill, std::string name) {
  while (to_fill.empty()) {
    std::cout << "Enter " << name << ": ";
    std::getline(std::cin, to_fill);
	if ((std::cin.eof() || std::cin.bad()))
	{
      std::cout << std::endl << "EOF" << std::endl;
	  exit (0);
	}
    if (to_fill.empty())
      std::cout << name << " cannot be empty" << std::endl;
  }
}

Contact Contact::fromUserInput() {
  Contact contact;

  get_input(contact.firstname, "firstname");
  get_input(contact.lastname, "lastname");
  get_input(contact.nickname, "nickname");
  while (contact.phone == 0) {
    long phone_number;
    std::string phone;
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
	if (std::cin.eof() || std::cin.bad())
	{
      std::cout << std::endl << "EOF" << std::endl;
	  exit (0);
	}
    std::stringstream ss(phone);
    if (ss.fail() || !(ss >> phone_number)) {
      std::cout << "Invalid phone number" << std::endl;
      contact.phone = 0;
      continue;
    }
    if (phone_number < 0) {
      std::cout << "Invalid phone number" << std::endl;
      contact.phone = 0;
      continue;
    }
    contact.phone = phone_number;
  }
  get_input(contact.darkest_secret, "darkest secret");
  return contact;
}
