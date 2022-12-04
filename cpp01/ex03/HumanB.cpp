#include "HumanB.h"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}
HumanB::HumanB(std::string name, Weapon &weapon)
    : name(name), weapon(&weapon) {}
HumanB::~HumanB() {}

void HumanB::attack() {
  std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
