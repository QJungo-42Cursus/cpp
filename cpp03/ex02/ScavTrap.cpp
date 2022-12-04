#include "ScavTrap.h"
#include <iostream>

/* Constructors and Destructors */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

/* Member Functions */

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode."
            << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}
