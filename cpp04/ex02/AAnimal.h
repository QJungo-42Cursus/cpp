#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <iostream>

class AAnimal {
public:
  /* Constructor and Destructor */
  AAnimal(const AAnimal &other);
  virtual ~AAnimal();

  /* Operator Overload */
  AAnimal &operator=(const AAnimal &other);

  /* Getters */
  std::string getType() const;

  /* Methods */
  virtual void makeSound() const = 0;

protected:
  std::string type;
  AAnimal();
};

#endif /* ANIMAL_H */
