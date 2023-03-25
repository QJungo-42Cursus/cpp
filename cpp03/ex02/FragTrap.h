#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"
#include <iostream>

class FragTrap : public ClapTrap {
public:
  /* Constructors and Destructors */
  FragTrap(std::string name);
  FragTrap(const FragTrap &other);
  virtual ~FragTrap();

  /* Operators Overload */
  FragTrap &operator=(const FragTrap &other);

  /* Methods */
  void highFivesGuys();
};

#endif /* FRAGTRAP_H */
