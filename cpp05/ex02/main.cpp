#include "Bureaucrat.h"
#include "Form.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

void endl() { std::cout << std::endl; }

int main() {
  ShrubberyCreationForm *form = new ShrubberyCreationForm("shrub", 5, 2);
  // Form form("form", 5, 2);
  Bureaucrat c("Cindy", 150);
  try {
    c.signForm(form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  endl();

  std::cout << form << std::endl;
  endl();

  Bureaucrat b("Bob", 1);
  try {
    b.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << b << std::endl;
  try {
    b.signForm(form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << form << std::endl;
}
