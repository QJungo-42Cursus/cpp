#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  ~WrongAnimal();
  std::string getType() const;
  virtual void makeSound() const;

protected:
  std::string type;
};

#endif /* WRONGANIMAL_H */
