#include "Animal.h"

Animal::Animal() {
  std::cout << "Animal constructor called" << std::endl;
  type = "Animal";
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
