#include "AMateria.h"

/* Constructor and Destructor */
AMateria::AMateria() : type("AMateria") {
  std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
  std::cout << "AMateria type constructor called" << std::endl;
  this->type = type;
}

AMateria::AMateria(const AMateria &other) {
  std::cout << "AMateria copy constructor called" << std::endl;
  type = other.type;
}

AMateria::~AMateria() {
  std::cout << "AMateria destructor called" << std::endl;
}

/* Operator Overload */
AMateria &AMateria::operator=(const AMateria &other) {
  std::cout << "AMateria assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

/* Getters */
std::string AMateria::getType() const { return type; }
