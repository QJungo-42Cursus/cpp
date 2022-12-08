#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  ~WrongAnimal();
  std::string getType() const;
  virtual void makeSound() const;

  /* Operator Overload */
  WrongAnimal &operator=(const WrongAnimal &other);

protected:
  std::string type;
};

#endif /* WRONGANIMAL_H */
