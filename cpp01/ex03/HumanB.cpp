#include "HumanB.h"

/* Constructor and Destructor */
HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr) {}
HumanB::HumanB(std::string name, Weapon &weapon)
    : _name(name), _weapon(&weapon) {}
HumanB::~HumanB() {}

/* Methods */
void HumanB::attack() {
  std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

/* Setter */
void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }
