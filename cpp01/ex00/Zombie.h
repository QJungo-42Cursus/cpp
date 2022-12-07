#include <iostream>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie();
  void announce();

private:
  std::string _name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
