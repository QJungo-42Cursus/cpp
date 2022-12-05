#include "Dog.h"

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog &other) {
  std::cout << "Dog copy constructor called" << std::endl;
  type = other.type;
  brain = new Brain();
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
