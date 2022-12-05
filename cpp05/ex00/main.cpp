#include "Bureaucrat.h"
#include <iostream>

// TODO mettre ailleurs
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}

int main() {
  Bureaucrat c("Cindy", 150);
  Bureaucrat b("Bob", 1);
  try {
    c.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << c;
}
