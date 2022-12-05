#include "Animal.h"

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
