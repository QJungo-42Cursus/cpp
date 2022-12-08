#include "Bureaucrat.h"
#include <iostream>

int main() {
  Bureaucrat c("Cindy", 150);
  Bureaucrat b("Bob", 1);
  try {
    c.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Le grade de " << c.getName() << " est trop bas (" << e.what()
              << ")" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << c << std::endl;
  // c.decrementGrade();
}
