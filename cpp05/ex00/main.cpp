#include "Bureaucrat.h"
#include <iostream>

int main()
{
  Bureaucrat c("Cindy", 150);
  Bureaucrat b("Bob", 1);
  try
  {
    c.decrementGrade();
  }
  catch (Bureaucrat::GradeTooLowException &e)
  {
    std::cout << "Le grade de " << c.getName() << " est trop bas (" << e.what()
              << ")" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << c << std::endl;
  try
  {
    b.incrementGrade();
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << "Le grade de " << b.getName() << " est trop haut (" << e.what()
              << ")" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << b << std::endl;
  return 0;
}
