#include "Animal.h"

Animal::Animal() {
  std::cout << "Animal constructor called" << std::endl;
  type = "Animal";
  brain = new Brain();
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
  delete brain;
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
