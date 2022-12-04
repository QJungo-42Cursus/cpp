#include "FragTrap.h"
#include <iostream>

/* Constructors and Destructors */

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

/* Member Functions */

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << _name << " gives high fives to everyone!"
            << std::endl;
}
