#include "Dog.h"

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }
