#include "Zombie.h"
#include <iostream>

/// cree un nouveau zombie dans la stack et annonce son nom
void Zombie::randomChump(std::string name) {
  Zombie zombie = Zombie(name);
  zombie._name = name;
  zombie.announce();
}
