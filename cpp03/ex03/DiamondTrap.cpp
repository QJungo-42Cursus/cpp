#include "DiamondTrap.h"
#include "color.h"
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

/* Operators Overload */
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
  if (this != &other) {
    this->_name = other._name;
    this->FragTrap::_hitPoints = other.FragTrap::_hitPoints;
    this->FragTrap::_energyPoints = other.FragTrap::_energyPoints;
    this->FragTrap::_attackDamage = other.FragTrap::_attackDamage;
  }
  std::cout << "DiamondTrap operator= called, ";
  ScavTrap::_printSpecs();
  return *this;
}

/* Member Functions */
void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ScavTrap name: " << ScavTrap::_name << std::endl;
  std::cout << "FragTrap name: " << FragTrap::_name << std::endl;
}

/* Methods overrde */
void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}
