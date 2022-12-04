#include "ClapTrap.h"
#include <iostream>

int main() {
  ClapTrap clapTrap("ClapTrap_name");
  clapTrap.attack("target");
  clapTrap.takeDamage(10);
  clapTrap.beRepaired(10);

  return 0;
}
