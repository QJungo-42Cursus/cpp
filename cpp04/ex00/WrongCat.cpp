#include "WrongCat.h"

void WrongCat::makeSound() const { std::cout << "Bonsoir" << std::endl; }

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  type = other.type;
}

/* Operator Overload */
WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "Wrong Cat assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
