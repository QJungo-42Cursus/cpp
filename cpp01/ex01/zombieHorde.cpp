#include "Zombie.h"
#include <iostream>

Zombie *Zombie::zombieHorde(int N, std::string name) {
  Zombie *zombies = new Zombie[N];
  for (int i = 0; i < N; i++) {
    zombies[i]._name = name;
  }
  return zombies;
}