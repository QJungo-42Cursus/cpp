#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "FragTrap.h"
#include "ScavTrap.h"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const &other);
  ~DiamondTrap();

  /* Operators Overload */
  DiamondTrap &operator=(DiamondTrap const &other);

  /* Methods overide */
  void attack(std::string const &target);

  /* Methods */
  void whoAmI();

private:
  std::string _name;
};

#endif /* DIAMONDTRAP_H */
