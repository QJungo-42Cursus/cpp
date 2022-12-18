#include "Zombie.h"
#include <iostream>

// TODO est-ce qu'il existe un moyen de creer le tableau tout en instanciant
// chaque zombie avec le meme nom ?
// TODO est-ce que ca ne devrait pas etre en majuscule ?
Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombies = new Zombie[N];
  for (int i = 0; i < N; i++) {
    zombies[i].setName(name);
  }
  return zombies;
}
