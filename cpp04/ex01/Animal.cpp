#include "Animal.h"

/* Constructor and Destructor */
Animal::Animal() : type("Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor called" << std::endl;
  type = other.type;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

/* Operator Overload */
Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

/* Getters */
std::string Animal::getType() const { return type; }

/* Methods */
void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
