#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

int main() {
  /*
  const AAnimal *meta = new AAnimal();
  meta->makeSound();
  delete meta;
  */

  const AAnimal *i = new Cat();
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  delete i;

  const AAnimal *j = new Dog();
  std::cout << j->getType() << " " << std::endl;
  j->makeSound();
  delete j;

  // TODO devrait afficher le son du wrong animal ?
  const WrongCat *wrongCat = new WrongCat();
  wrongCat->makeSound();
  delete wrongCat;
  AAnimal *animals[10];

  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }
}
