#include "Zombie.h"
#include <iostream>

/* Constructor */
Zombie::Zombie() {}
Zombie::Zombie(std::string name) { _name = name; }
Zombie::~Zombie() {}

/* Methods */
void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Setters */
void Zombie::setName(std::string name) { _name = name; }
