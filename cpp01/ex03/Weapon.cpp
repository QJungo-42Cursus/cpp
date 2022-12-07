#include "Weapon.h"

/* Constructor and Destructor */
Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

/* Setter */
void Weapon::setType(std::string type) { _type = type; }

/* Getter */
const std::string &Weapon::getType() const { return _type; }
