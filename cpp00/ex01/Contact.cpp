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

#include <iomanip>
#include <sstream>

void Contact::display(int index) {
  std::ostringstream oss;

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
