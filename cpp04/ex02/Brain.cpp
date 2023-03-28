#include "Brain.h"

/* Constructor and Destructor */
Brain::Brain() { std::cout << "Brain created" << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor called" << std::endl;
  for (int i; i < 100; i++) {
    this->ideas[i] = other.ideas[i];
  }
}

Brain::~Brain() { std::cout << "Brain destroyed" << std::endl; }

/* Operator Overload */
Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain assignation operator called" << std::endl;
  if (this != &other) {
    for (int i; i < 100; i++) {
      this->ideas[i] = other.ideas[i];
    }
  }
  return *this;
}
