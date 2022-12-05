#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include <iostream>

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &other);
  ~Cat();
  void makeSound() const;
};

#endif /* CAT_H */
