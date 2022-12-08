#include "Dog.h"

/* Constructor and Destructor */
Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog &other) {
  if (other.type != "Dog") {
    throw std::invalid_argument("Invalid type"); // TODO to much ?
  }
  std::cout << "Dog copy constructor called" << std::endl;
  type = other.type;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

/* Methods override */
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
