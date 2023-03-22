#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {
public:
  /* Constructors and Destructors */
  ClapTrap();
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();
  ClapTrap(std::string name);

  /* Operators */
  ClapTrap &operator=(const ClapTrap &other);

  /* Methods */
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

  /* Methods */
  bool _canAct() const;
  void _printSpecs() const;
};

#endif /* CLAPTRAP_H */
