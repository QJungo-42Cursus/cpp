#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class Animal {
public:
  Animal();
  Animal(std::string name);
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();
  virtual void makeSound() const;
  std::string getName() const;
  void setName(std::string name);
};

#endif /* CLAPTRAP_H */
