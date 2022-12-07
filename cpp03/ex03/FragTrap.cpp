#include "FragTrap.h"
#include <iostream>

/* Constructors and Destructors */

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap constructor called, ";
  _printSpecs();
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
  std::cout << "FragTrap copy constructor called, ";
  _printSpecs();
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

/* Member Functions */

void FragTrap::highFivesGuys() {
  std::cout << COLOR_GREEN << _name << COLOR_RESET
            << " gives high fives to everyone!" << std::endl;
}
