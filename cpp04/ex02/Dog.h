#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <iostream>

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  ~Dog();
  void makeSound() const;
};

#endif /* DOG_H */
