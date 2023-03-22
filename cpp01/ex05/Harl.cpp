#include "Harl.h"
#include <iostream>

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {
  complainFunc[DEBUG] = &Harl::debug;
  complainFunc[INFO] = &Harl::info;
  complainFunc[WARNING] = &Harl::warning;
  complainFunc[ERROR] = &Harl::error;
}

void Harl::debug() const {
  std::cout << "DEBUG: bon ba ca part sur un test quoi" << std::endl;
}

void Harl::info() const {
  std::cout << "INFO: au cas ou le programme a commence" << std::endl;
}

void Harl::warning() const {
  std::cout << "WARNING: oula. C'est un probleme" << std::endl;
}

void Harl::error() const {
  std::cout << "ERROR: t srx ?? C'est un gros problem" << std::endl;
}

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
