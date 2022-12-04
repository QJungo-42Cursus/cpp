#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>

int main() {
  /*
  ClapTrap clapTrap("ClapTrap_name");
  clapTrap.attack("target");
  clapTrap.takeDamage(10);
  clapTrap.beRepaired(10);

  ScavTrap scavTrap("ScavTrap_name");
  scavTrap.attack("target");
  scavTrap.takeDamage(10);
  scavTrap.guardGate();
  scavTrap.beRepaired(10);
  */

  FragTrap fragTrap("FragTrap_name");
  fragTrap.attack("target");
  fragTrap.takeDamage(10);
  fragTrap.beRepaired(10);
  fragTrap.highFivesGuys();
  return 0;
}
