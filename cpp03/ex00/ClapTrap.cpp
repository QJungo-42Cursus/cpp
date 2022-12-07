#include "ClapTrap.h"

/* Constructors and Destructors */
ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called, ";
  printSpecs();
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap constructor called, ";
  printSpecs();
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  *this = other;
  std::cout << "ClapTrap copy constructor called, ";
  printSpecs();
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

/* Operators */
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  std::cout << "ClapTrap assignment operator called, ";
  printSpecs();
  return *this;
}

/* Actions Methods */
void ClapTrap::attack(const std::string &target) {
  if (!canAct())
    return;
  _energyPoints--;
  std::cout << _name << " attacks " << target << ", causing " << _attackDamage
            << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  _hitPoints = _hitPoints < 0 ? 0 : _hitPoints;
  if (_hitPoints == 0) {
    std::cout << _name << " has died after taking " << amount
              << " points of damage" << std::endl;
  } else {
    std::cout << _name << " has taken " << amount << " points of damage"
              << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!canAct())
    return;
  _energyPoints--;
  _hitPoints += amount;
  std::cout << _name << " is repaired for " << amount << " points!"
            << std::endl;
}

bool ClapTrap::canAct() const {
  if (_energyPoints < 1) {
    std::cout << _name << " has no energy to attack" << std::endl;
    return false;
  }
  if (_hitPoints < 1) {
    std::cout << _name << " is dead (and cannot do his attack)" << std::endl;
    return false;
  }
  return true;
}

/* Display */
void ClapTrap::printSpecs() const {
  std::cout << _name << " has " << _hitPoints << " hit points, "
            << _energyPoints << " energy points and " << _attackDamage
            << " attack damage" << std::endl;
}
