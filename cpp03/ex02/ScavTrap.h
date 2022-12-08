#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.h"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
  /* Constructors and Destructors */
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap();

  /* Operators Overload */
  ScavTrap &operator=(const ScavTrap &other);

  /* Methods */
  void attack(std::string const &target);
  void guardGate();
};

#endif /* SCAVTRAP_H */
