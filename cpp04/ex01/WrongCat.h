#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.h"
#include <iostream>

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  ~WrongCat();
  void makeSound() const;
};

#endif /* WRONGCAT_H */
