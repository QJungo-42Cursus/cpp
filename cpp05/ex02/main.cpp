#include "Bureaucrat.h"
#include "Form.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

void endl() { std::cout << std::endl; }

int main() {
  ShrubberyCreationForm *form = new ShrubberyCreationForm("shrub");
  Bureaucrat c("Cindy", 150);
  try {
    c.signForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  std::cout << c << std::endl;
  endl();

  Bureaucrat b("Bob", 1);
  try {
    b.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << b << std::endl;
  try {
    b.signForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  endl();

  try {
    c.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  } 
  try {
    b.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
