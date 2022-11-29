#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(std::string firstname, std::string lastname,
                 std::string nickname, std::string phone,
                 std::string darkest_secret) {
  this->firstname = firstname;
  this->lastname = lastname;
  this->nickname = nickname;
  this->phone = phone;
  this->darkest_secret = darkest_secret;
}

void Contact::display(int index) {
  std::cout << index << " | " << firstname << " | " << lastname << " | "
            << nickname << std::endl;
}

void Contact::full_display(int index) {
  std::cout << index << " | " << firstname << " | " << lastname << " | "
            << nickname << " | " << phone << " | " << darkest_secret
            << std::endl;
}

Contact Contact::fromUserInput() {
  std::string firstname;
  std::string phone;
  std::string lastname;
  std::string nickname;
  std::string darkest_secret;

  std::cout << "Enter firstname: ";
  std::cin >> firstname;
  std::cout << "Enter lastname: ";
  std::cin >> lastname;
  std::cout << "Enter nickname: ";
  std::cin >> nickname;
  std::cout << "Enter phone: ";
  std::cin >> phone;
  std::cout << "Enter darkest_secret: ";
  std::cin >> darkest_secret;
  return (Contact(firstname, lastname, nickname, phone, darkest_secret));
}
