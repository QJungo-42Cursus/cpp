#include <iostream>

class Zombie {
public:
  Zombie();
  ~Zombie();
  static Zombie *zombieHorde(int N, std::string name);
  static Zombie *newZombie(std::string name);
  void announce();

private:
  std::string _name;
};
