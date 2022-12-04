#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {
private:
  std::string _name;
  int _hitPoints = 10;
  int _energyPoints = 10;
  int _attackDamage = 0;

public:
  // Coplien's form
  ClapTrap(std::string name);                 /// Constructor
  ClapTrap(const ClapTrap &other);            /// Copy constructor
  ~ClapTrap();                                /// Destructor
  ClapTrap &operator=(const ClapTrap &other); /// Assignment operator


  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_H */
