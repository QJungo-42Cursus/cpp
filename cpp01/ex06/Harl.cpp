#include "Harl.h"
#include <iostream>

Harl::Harl() {
  complainFunc[DEBUG] = &Harl::debug;
  complainFunc[INFO] = &Harl::info;
  complainFunc[WARNING] = &Harl::warning;
  complainFunc[ERROR] = &Harl::error;
}

Harl::Level Harl::_level = Harl::DEBUG;

const std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Harl::setLevel(std::string level) {
  for (int i = 0; i < 4; i++) {
    if (level == Harl::levels[i]) {
      Harl::_level = (Harl::Level)i;
      return;
    }
  }
  std::cerr << "Usage: <level>" << std::endl
            << "level must be one of the following: ";
  for (int i = 0; i < 4; i++) {
    std::cerr << "'" << levels[i] << "' ";
  }
  std::cerr << std::endl;
  exit(1);
}

void Harl::debug() const {
  std::cout << "[ DEBUG ]" << std::endl << " bon ba ca part sur un test quoi" << std::endl;
}

void Harl::info() const {
  std::cout << "[ INFO ]" << std::endl << "au cas ou le programme a commence" << std::endl;
}

void Harl::warning() const {
  std::cout << "[ WARNING ]" << std::endl << "oula. C'est un probleme" << std::endl;
}

void Harl::error() const {
  std::cout << "[ ERROR ]" << std::endl << "t srx ?? C'est un gros problem" << std::endl;
}

void Harl::complain(std::string level) {
  Harl harl;
  Harl::Level current_level;
  for (int i = ERROR; i >= _level; i--) {
    if (level == harl.levels[i]) {
      current_level = (Harl::Level)i;
      (harl.*harl.complainFunc[current_level])();
      break;
    }
  }
}
