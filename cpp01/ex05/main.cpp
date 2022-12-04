#include "Harl.h"
#include <iostream>

int main(int argc, char **argv) {
  Harl::complain("debug");
  Harl::complain("info");
  Harl::complain("warning");
  Harl::complain("error");
  Harl::complain("debusdfg");
  return 0;
}
