#include "ClapTrap.h"
#include <iostream>

int main() {
  ClapTrap clapTrap("Henry");
  ClapTrap clapTrap2("Claire");

  clapTrap.attack("Claire");
  clapTrap2.takeDamage(0);

  clapTrap.takeDamage(10);
  clapTrap.beRepaired(10);

  return 0;
}
