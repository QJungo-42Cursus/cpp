#include "AAnimal.h"

/* Constructor and Destructor */
AAnimal::AAnimal() : type("AAnimal") {
  std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
  std::cout << "AAnimal copy constructor called" << std::endl;
  type = other.type;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

/* Operator Overload */
AAnimal &AAnimal::operator=(const AAnimal &other) {
  std::cout << "AAnimal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

/* Getters */
std::string AAnimal::getType() const { return type; }
