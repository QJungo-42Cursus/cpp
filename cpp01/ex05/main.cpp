#include "Harl.h"
#include <iostream>

int main() {
  std::cout << "n'importe quoi :";
  Harl::complain("debusdfg");
  std::cout << std::endl;
  std::cout << "devrait marcher :" << std::endl;
  Harl::complain("DEBUG");
  Harl::complain("INFO");
  Harl::complain("WARNING");
  Harl::complain("ERROR");
  return 0;
}
