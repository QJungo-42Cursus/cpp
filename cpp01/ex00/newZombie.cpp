#include "Zombie.h"
#include <iostream>

/// cree un nouveau zombie dans la heap
Zombie *Zombie::newZombie(std::string name) {
  Zombie *newZombie = new Zombie(name);
  newZombie->_name = name;
  return newZombie;
}
