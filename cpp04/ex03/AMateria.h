#ifndef AMATERIA_H
#define AMATERIA_H
#include "ICharacter.h"
#include <iostream>

class AMateria {
public:
  /* Constructor and Destructor */
  AMateria(const AMateria &other);
  AMateria(std::string const &type);
  virtual ~AMateria();

  /* Operator Overload */
  AMateria &operator=(const AMateria &other);

  /* Getters */
  std::string getType() const;

  /* Methods */
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string type;
  AMateria();
};

#endif /* AMATERIA_H */
