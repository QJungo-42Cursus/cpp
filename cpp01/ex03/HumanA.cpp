#include "HumanA.h"

/* Constructor and Destructor */
HumanA::HumanA(std::string name, Weapon &weapon)
    :  _weapon(weapon), _name(name) {}

HumanA::~HumanA() {}

/* Methods */
void HumanA::attack() {
  std::cout << this->_name << " attacks with his " << this->_weapon.getType()
            << std::endl;
}
