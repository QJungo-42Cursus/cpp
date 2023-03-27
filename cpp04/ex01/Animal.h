#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include "Brain.h"

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

private:
  Brain *_brain;
};

#endif /* ANIMAL_H */
