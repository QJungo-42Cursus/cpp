#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.h"
#include <iostream>

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string name);
  ~FragTrap();

  void highFivesGuys();
};

#endif /* FRAGTRAP_H */
