#include "Cat.h"

/* Constructor and Destructor */
Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat &other) {
  std::cout << "Cat copy constructor called" << std::endl;
  type = other.type;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

/* Operator Overloads */
Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignment operator called" << std::endl;
  type = other.type;
  return *this;
}

/* Methods override */
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

