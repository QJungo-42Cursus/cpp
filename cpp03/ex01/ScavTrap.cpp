#include "ScavTrap.h"
#include "color.h"
#include <iostream>

/* Constructors and Destructors */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  // On ne peut pas initialiser les attributs de la classe mère dans le corps
  // (list initialiser) pour eviter le cas ou il serai const par exemple
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap constructor called, ";
  _printSpecs();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::cout << "ScavTrap assignation operator called, ";
  _printSpecs();
  return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap copy constructor called, ";
  _printSpecs();
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called for " << COLOR_MAGENTA << _name
            << COLOR_RESET << std::endl;
}

/* Member Functions */
void ScavTrap::guardGate() {
  if (!_canAct("guardGate"))
    return;
  std::cout << COLOR_MAGENTA << _name << COLOR_RESET
            << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  if (!_canAct("attack"))
    return;
  std::cout << COLOR_MAGENTA << _name << COLOR_RESET
            << " attacks like a true ScavTrap " << COLOR_BOLD << target
            << COLOR_RESET << ", causing " << _attackDamage
            << " points of damage!" << std::endl;
}
