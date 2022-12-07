#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <iostream>

class HumanB {
public:
  /* Constructor and Destructor */
  HumanB(std::string name);
  HumanB(std::string name, Weapon &weapon);
  ~HumanB();

  /* Methods */
  void attack();

  /* Setter */
  void setWeapon(Weapon &weapon);

private:
  /* Attributes */
  Weapon *_weapon;
  std::string _name;
};

#endif /* HUMANB_H */
