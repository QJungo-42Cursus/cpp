#include "Cat.h"
#include "Brain.h"

/* Constructor and Destructor */
Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type = "Cat";
  _brain = new Brain();
}

Cat::Cat(const Cat &other) {
  std::cout << "Cat copy constructor called" << std::endl;
  type = other.type;
  _brain = other._brain;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl; 
}

/* Operator Overloads */
Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignment operator called" << std::endl;
  type = other.type;
  _brain = other._brain;
  return *this;
}

/* Methods override */
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

