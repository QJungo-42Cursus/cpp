#include "DiamondTrap.h"
#include <iostream>

/* Constructors and Destructors */

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
  std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

/* Member Functions */

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ScavTrap name: " << ScavTrap::_name << std::endl;
  std::cout << "FragTrap name: " << FragTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}
