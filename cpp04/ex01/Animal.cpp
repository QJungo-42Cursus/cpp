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

/* TODO utile ?
Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}
*/

/* Operator Overload */
Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
    delete brain;
    brain = new Brain(*other.brain);
  }
  return *this;
}
std::string Animal::getType() const { return type; }

/* Methods */
void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
