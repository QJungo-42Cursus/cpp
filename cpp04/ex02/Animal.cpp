#include "Animal.h"

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }

/* Operator Overload */
Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}
// TODO wtf
