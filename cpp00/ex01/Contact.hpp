#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
private:
  std::string firstname;
  std::string lastname;
  std::string nickname;
  unsigned int phone;
  std::string darkest_secret;

public:
  Contact();
  Contact(std::string firstname, std::string lastname, std::string nickname,
          unsigned int phone, std::string darkest_secret);
  static Contact fromUserInput();
  void display(int index);
  void full_display(int index);
};

#endif /* CONTACT_HPP */
