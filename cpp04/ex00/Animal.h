#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal {
public:
  Animal();
  ~Animal();
  std::string getType() const; // const at the end mean that the function will not modify the object
  virtual void makeSound() const; // virtual means that the function can be overriden in a derived class

protected:
  std::string type;
};

#endif /* ANIMAL_H */
