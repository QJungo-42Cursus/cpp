#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

int main() {
  const Animal *meta = new Animal();
  meta->makeSound();
  delete meta;

  const Animal *i = new Cat();
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  delete i;

  const Animal *j = new Dog();
  std::cout << j->getType() << " " << std::endl;
  j->makeSound();
  delete j;

  const WrongCat *wrongCat = new WrongCat();
  wrongCat->makeSound();
  delete wrongCat;

  Animal *animals[10];

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
