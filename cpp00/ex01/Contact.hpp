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
  static Contact fromUserInput();
  void display(int index) const;
  void full_display(int index) const;
};

#endif /* CONTACT_HPP */
