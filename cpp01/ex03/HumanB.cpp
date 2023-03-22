#include "HumanB.h"

/* Constructor and Destructor */
HumanB::HumanB(std::string name) :  _weapon(nullptr), _name(name) {}
HumanB::HumanB(std::string name, Weapon &weapon)
    :  _weapon(&weapon), _name(name) {}
HumanB::~HumanB() {}

/* Methods */
void HumanB::attack() {
  std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

/* Setter */
void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }
