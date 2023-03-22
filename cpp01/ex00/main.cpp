#include "Zombie.h"
#include <iostream>

int main() {
  Zombie *zombie = newZombie("KikiOnTheHeap");
  zombie->announce();
  delete zombie;
  randomChump("KikiOnTheStack");
  return 0;
}
