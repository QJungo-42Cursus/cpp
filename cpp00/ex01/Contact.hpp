#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
private:
  std::string phone;
  std::string darkest_secret;

public:
  std::string firstname;
  std::string lastname;
  std::string nickname;

  Contact(std::string firstname, std::string lastname, std::string nickname,
          std::string phone, std::string darkest_secret);
  void display(int index);
  void full_display(int index);
  static Contact fromUserInput();
};

#endif /* CONTACT_HPP */
