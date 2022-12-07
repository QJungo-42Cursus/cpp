#include "DiamondTrap.h"
#include <iostream>

/* Constructors and Destructors */
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
  std::cout << "DiamondTrap constructor called" << std::endl;
  ScavTrap::_printSpecs();
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
    : ScavTrap(other), FragTrap(other) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  *this = other;
  ScavTrap::_printSpecs();
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called for " << _name << std::endl;
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
