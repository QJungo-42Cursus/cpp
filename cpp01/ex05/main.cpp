#include "Harl.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "n'importe quoi :";
  Harl::complain("debusdfg");
  std::cout << std::endl << std::endl;

  std::cout << "devrait marcher :";
  Harl::complain("debug");
  Harl::complain("info");
  Harl::complain("warning");
  Harl::complain("error");
  return 0;
}
