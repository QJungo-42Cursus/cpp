#include <iostream>

class Zombie {
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce();
  void setName(std::string name);

private:
  std::string _name;
};

Zombie *zombieHorde(int N, std::string name);
// static Zombie *newZombie(std::string name);
