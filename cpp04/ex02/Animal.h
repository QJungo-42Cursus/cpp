#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <iostream>

class Animal {
public:
  virtual ~Animal() = default;
  virtual std::string getType() const;
  virtual void makeSound() const;

protected:
  Animal() = default;
  Brain *brain;
  std::string type;
};

#endif /* ANIMAL_H */
