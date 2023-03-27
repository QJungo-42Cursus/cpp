#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.h"
#include <iostream>

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);
  virtual ~WrongCat();

  /* Operator Overload */
  WrongCat &operator=(const WrongCat &other);

  void makeSound() const;
};

#endif /* WRONGCAT_H */
