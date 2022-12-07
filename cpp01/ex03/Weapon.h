#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
public:
  /* Constructor */
  Weapon(std::string type);
  ~Weapon();

  /* Getter */
  const std::string &getType() const;

  /* Setter */
  void setType(std::string type);

private:
  std::string _type;
};

#endif /* WEAPON_H */
