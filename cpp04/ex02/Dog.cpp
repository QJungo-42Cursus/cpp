#include "Dog.h"
#include "Brain.h"

/* Constructor and Destructor */
Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
  _brain = new Brain();
}

Dog::Dog(const Dog &other) {
  if (other.type != "Dog") {
    throw std::invalid_argument("Invalid type"); // TODO to much ?
  }
  std::cout << "Dog copy constructor called" << std::endl;
  type = other.type;
  _brain = other._brain;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog assignment operator called" << std::endl;
  type = other.type;
  _brain = other._brain;
  return *this;
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "Dog destructor called" << std::endl;
}

/* Methods override */
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
