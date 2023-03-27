#ifndef DOG_H
#define DOG_H
#include "Animal.h"

class Dog : public Animal {
public:
  /* Constructor and Destructor */
  Dog();
  Dog(const Dog &other);
  virtual ~Dog();

  /* Operator Overloads */
  Dog &operator=(const Dog &other);

  /* Methods override */
  void makeSound() const;
};

#endif /* DOG_H */
