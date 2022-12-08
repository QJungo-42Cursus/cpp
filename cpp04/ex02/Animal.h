#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <iostream>

class Animal {
public:
  /* Constructors and Destructors */
  Animal(const Animal &other);
  virtual ~Animal();

  /* Operator Overload */
  Animal &operator=(const Animal &other);

  virtual std::string getType() const;
  virtual void makeSound() const;

protected:
  Animal();
  Brain *brain;
  std::string type;
};

#endif /* ANIMAL_H */
