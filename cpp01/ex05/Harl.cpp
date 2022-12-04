#include "Harl.h"
#include <iostream>

Harl::Harl() {
  complainFunc[DEBUG] = &Harl::debug;
  complainFunc[INFO] = &Harl::info;
  complainFunc[WARNING] = &Harl::warning;
  complainFunc[ERROR] = &Harl::error;
}
Harl::~Harl() {}

void Harl::complain(std::string level) {
  Harl harl;
  Harl::Level current_level;
  for (int i = 0; i < 4; i++) {
    if (level == harl.levels[i]) {
      current_level = (Harl::Level)i;
      (harl.*harl.complainFunc[current_level])();
      break;
    }
  }
}

void Harl::debug() {
  std::cout << "DEBUG bon ba ca part sur un test quoi" << std::endl;
}

void Harl::info() {
  std::cout << "INFO au cas ou le programme a commence" << std::endl;
}

void Harl::warning() { std::cout << "WARNING oula" << std::endl; }

void Harl::error() { std::cout << "ERROR t srx ??" << std::endl; }
