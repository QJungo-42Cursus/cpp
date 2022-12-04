#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <iostream>

class HumanB {
public:
  Weapon *weapon;
  std::string name;

  HumanB(std::string name);
  HumanB(std::string name, Weapon &weapon);
  ~HumanB();

  void attack();
  void setWeapon(Weapon &weapon);
};

#endif /* HUMANB_H */
