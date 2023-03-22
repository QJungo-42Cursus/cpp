#include "ClapTrap.h"
#include "ScavTrap.h"
#include <iostream>

int main() {
  ClapTrap *jack = new ClapTrap("Jack_the_Clap");
  ScavTrap thierry("Thierry_the_ScavTrap");
  ScavTrap eude("Eude_the_ScavTrap");
  ScavTrap thierry2(thierry);
  jack->attack("Thierry_the_ScavTrap");
  thierry.takeDamage(jack->getAttackDamage());
  thierry.attack("Eude_the_ScavTrap");
  eude.takeDamage(thierry.getAttackDamage());
  /*
  while (eude.getEnergyPoints() > 0) {
    eude.beRepaired(10);
  }
  */
  std::cout << eude.getEnergyPoints() << std::endl;
  eude.beRepaired(10);
  thierry.guardGate();
  delete jack;
  return 0;
}
