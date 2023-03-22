#include "Zombie.h"
#include <iostream>

int main() {
  int N = 5;
  Zombie *zombies = zombieHorde(N, "veryCommonName");
  while (N--) {
    zombies[N].announce();
  }
  delete[] zombies;
  return 0;
}
