#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string name) { _name = name; }

void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
