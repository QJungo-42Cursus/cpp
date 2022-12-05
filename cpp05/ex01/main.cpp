#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

// TODO mettre ailleurs
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}

std::ostream &operator<<(std::ostream &os, Form const &b) {
  os << b.getName() << ", form grade " << b.getGradeToSign() << " to sign and "
     << b.getGradeToExecute() << " to execute";
  return os;
}

int main() {
  Form form("form", 1, 1);
  Bureaucrat c("Cindy", 150);
  form.beSigned(c);
  std::cout << form << std::endl;
  return 0;
  Bureaucrat b("Bob", 1);
  try {
    c.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << c;
  // c.decrementGrade();
}
