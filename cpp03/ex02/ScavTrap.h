#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.h"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
  ScavTrap(std::string name);
  ~ScavTrap();
  void attack(std::string const &target);
  void guardGate();
};

#endif /* SCAVTRAP_H */
