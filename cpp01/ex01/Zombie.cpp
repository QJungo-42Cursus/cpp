#include "Zombie.h"
#include <iostream>

// Zombie::Zombie(std::string name) { _name = name; }
Zombie::Zombie() {}
Zombie::~Zombie() {}
void Zombie::announce() {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/// cree un nouveau zombie dans la heap
Zombie *Zombie::newZombie(std::string name) {
  Zombie *newZombie = new Zombie;
  newZombie->_name = name;
  return newZombie;
}
