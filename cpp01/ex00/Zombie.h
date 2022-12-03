#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		Zombie* newZombie(std::string name);
		static void randomChump(std::string name);
		void announce();
	private:
		std::string _name;
};
