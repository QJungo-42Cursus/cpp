#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <iostream>

class Animal {
public:
  /* Constructor and Destructor */
  Animal();
  Animal(const Animal &other);
  virtual ~Animal();

  /* Operator Overload */
  Animal &operator=(const Animal &other);

  /* Getters */
  std::string getType() const;

  /* Methods */
  virtual void makeSound() const;

protected:
  std::string type;
};

#endif /* ANIMAL_H */
