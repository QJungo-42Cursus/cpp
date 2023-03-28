#ifndef CHARACTER_H
#define CHARACTER_H
#include "AMateria.h"
#include "ICharacter.h"

class Character : public ICharacter {
private:
  AMateria *inventory;
  static const int maxMaterias = 4;
};

#endif /* CHARACTER_H */
