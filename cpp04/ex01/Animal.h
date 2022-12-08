#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <iostream>

class Animal {
public:
  Animal();
  Animal(const Animal &other);
  virtual ~Animal();

  std::string getType() const; // const at the end mean that the function will
                               // not modify the object
  virtual void makeSound() const; // virtual means that the function can be
                                  // overriden in a derived class

  /* Operator Overload */
  Animal &operator=(const Animal &other);

protected:
  Brain *brain;
  std::string type;
};

#endif /* ANIMAL_H */
