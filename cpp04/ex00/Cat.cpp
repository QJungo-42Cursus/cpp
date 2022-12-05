#include "Cat.h"

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }
