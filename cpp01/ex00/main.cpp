#include "Zombie.h"
#include <iostream>

int main() {
  Zombie *zombie = newZombie("KikiOnTheHeap");
  delete zombie;
  randomChump("KikiOnTheStack");
  return 0;
}
