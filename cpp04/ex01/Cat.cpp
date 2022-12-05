#include "Cat.h"

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat &other) {
  std::cout << "Cat copy constructor called" << std::endl;
  type = other.type;
  brain = new Brain();
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
