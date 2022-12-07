#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

// TODO color.h
#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"

#define COLOR_BOLD "\033[1m"
#define COLOR_RESET "\033[0m"

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
