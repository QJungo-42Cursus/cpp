#include "Bureaucrat.h"
#include "Form.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include <iostream>

void endl() { std::cout << std::endl; }

int main()
{
  Intern someRandomIntern;
  Form *rrf;
  try
  {
    rrf = someRandomIntern.makeForm("robotomy. request", "Bender");
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  std::cout << *rrf << std::endl;

  Bureaucrat b("Bob", 1);
  try
  {
    b.decrementGrade();
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << b << std::endl;

  try
  {
    b.signForm(*rrf);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *rrf << std::endl;
  endl();

  try
  {
    b.executeForm(*rrf);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  delete rrf;

  return 0;
}