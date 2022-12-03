#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <iostream>

class HumanA {
public:
  Weapon &weapon;
  std::string name;

  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  void attack();
};

#endif /* HUMANA_H */
