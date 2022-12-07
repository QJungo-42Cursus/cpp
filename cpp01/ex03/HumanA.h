#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <iostream>

class HumanA {
public:
  /* Constructor and Destructor */
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  /* Methods */
  void attack();

private:
  /* Private constructor */
  HumanA();

  /* Attributes */
  Weapon &_weapon;
  std::string _name;
};

#endif /* HUMANA_H */
