#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {
public:
  /* Constructors and Destructors */
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();

  /* Operators */
  ClapTrap &operator=(const ClapTrap &other);

  /* Methods */
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  bool canAct() const;
  void printSpecs() const;

private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
};

#endif /* CLAPTRAP_H */
