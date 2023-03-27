#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);

  /* Operator Overload */
  WrongAnimal &operator=(const WrongAnimal &other);

  std::string getType() const;
  void makeSound() const;

protected:
  std::string type;
};

#endif /* WRONGANIMAL_H */
