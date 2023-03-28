#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

void printEndl() { std::cout << std::endl; }

int main() {
  const Animal *meta = new Animal();
  meta->makeSound();
  delete meta;
  printEndl();

  const Animal *i = new Cat();
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  delete i;
  printEndl();

  const Animal *j = new Dog();
  std::cout << j->getType() << " " << std::endl;
  j->makeSound();
  delete j;
  printEndl();

  const Animal &other = *j;
  printEndl();
  // const Dog *k = new Dog(j); //-> ne peut que copier depuis un autre chien

  const WrongCat *wrongCat = new WrongCat();
  wrongCat->makeSound();
  delete wrongCat;
  printEndl();

  {
    const WrongAnimal *i = new WrongCat();
    i->makeSound();
  }
}
