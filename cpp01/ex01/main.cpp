#include "Zombie.h"
#include <iostream>

int main() {
  int N = 5;
  Zombie *zombies = zombieHorde(N, "ZombieName");
  while (N--) {
    zombies[N].announce();
  }
  delete[] zombies;
  return 0;
}
