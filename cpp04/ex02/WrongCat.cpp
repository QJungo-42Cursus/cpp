#include "WrongCat.h"

void WrongCat::makeSound() const { std::cout << "Bonsoir" << std::endl; }

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}
