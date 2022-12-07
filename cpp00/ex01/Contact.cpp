#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

Contact::Contact(std::string firstname, std::string lastname,
                 std::string nickname, unsigned int phone,
                 std::string darkest_secret)
    : firstname(firstname), lastname(lastname), nickname(nickname),
      phone(phone), darkest_secret(darkest_secret) {}

Contact::Contact()
    : firstname(""), lastname(""), nickname(""), phone(0), darkest_secret("") {}

void Contact::display(int index) {
  std::ostringstream oss;

  // TODO si plus grand que 10 char, tronquer
  oss << std::right << std::setw(10) << index << "|";
  oss << std::right << std::setw(10) << firstname << "|";
  oss << std::right << std::setw(10) << lastname << "|";
  oss << std::right << std::setw(10) << nickname << "|";
  oss << std::endl;
  std::cout << oss.str();
}

void Contact::full_display(int index) {
  std::cout << index << std::endl;
  std::cout << firstname << std::endl;
  std::cout << lastname << std::endl;
  std::cout << nickname << std::endl;
  std::cout << phone << std::endl;
  std::cout << darkest_secret << std::endl;
}

static void get_input(std::string &to_fill, std::string name) {
  while (to_fill.empty()) {
    std::cout << "Enter " << name << ": ";
    std::getline(std::cin, to_fill);
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
    std::string phone;
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::stringstream ss(phone);
    if (ss.fail() || !(ss >> contact.phone)) {
      std::cout << "Invalid phone number" << std::endl;
      contact.phone = 0;
    }
  }
  get_input(contact.darkest_secret, "darkest secret");

  return contact;
}
