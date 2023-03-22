#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap {
public:
  /* Constructors and Destructors */
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  virtual ~ClapTrap();

  /* Operators */
  ClapTrap &operator=(const ClapTrap &other);

  /* Methods */
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  /* Getters */
  int getHitPoints() const;
  int getAttackDamage() const;
  int getEnergyPoints() const;

protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
  bool _canAct(std::string action) const;
  void _printSpecs() const;
};

#endif /* CLAPTRAP_H */
