#include "ClapTrap.h"

/* Constructors and Destructors */
ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called, ";
  _printSpecs();
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap constructor called, ";
  _printSpecs();
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  *this = other;
  std::cout << "ClapTrap copy constructor called, ";
  _printSpecs();
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called for " << COLOR_BLUE << _name
            << COLOR_RESET << std::endl;
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
  _printSpecs();
  return *this;
}

/* Getters */
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }

/* Actions Methods */
void ClapTrap::attack(const std::string &target) {
  if (!_canAct("attack"))
    return;
  _energyPoints--;
  std::cout << COLOR_BLUE << _name << COLOR_RESET << " attacks " << COLOR_BOLD
            << target << COLOR_RESET << ", causing " << _attackDamage
            << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  _hitPoints = _hitPoints < 0 ? 0 : _hitPoints;
  if (_hitPoints == 0) {
    std::cout << COLOR_BLUE << _name << COLOR_RESET << " has died after taking "
              << amount << " points of damage" << std::endl;
  } else {
    std::cout << COLOR_BLUE << _name << COLOR_RESET << " has taken " << amount
              << " points of damage" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_canAct("be repaired"))
    return;
  _energyPoints--;
  _hitPoints += amount;
  std::cout << COLOR_BLUE << _name << COLOR_RESET << " is repaired for "
            << amount << " points!" << std::endl;
}

bool ClapTrap::_canAct(std::string action) const {
  if (_energyPoints < 1) {
    std::cout << COLOR_BLUE << _name << COLOR_RESET << " has no energy to "
              << action << std::endl;
    return false;
  }
  if (_hitPoints < 1) {
    std::cout << COLOR_BLUE << _name << COLOR_RESET
              << " is dead (and cannot do his " << action << ")" << std::endl;
    return false;
  }
  return true;
}

/* Display */
void ClapTrap::_printSpecs() const {
  std::cout << COLOR_BLUE << _name << COLOR_RESET << " has " << _hitPoints
            << " hit points, " << _energyPoints << " energy points and "
            << _attackDamage << " attack damage" << std::endl;
}
