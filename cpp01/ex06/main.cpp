#include "Harl.h"
#include <iostream>

// Prend en paramettre le niveau de gravité
int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
    return 1;
  }
  Harl::setLevel(argv[1]);

  Harl::complain("DEBUG");
  Harl::complain("INFO");
  Harl::complain("WARNING");
  Harl::complain("ERROR");
  return 0;
}
