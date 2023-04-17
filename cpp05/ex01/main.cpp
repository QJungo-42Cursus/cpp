#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

void endl() { std::cout << std::endl; }

int main()
{
  Form form("form", 5, 2);
  Bureaucrat c("Cindy", 150);
  try
  {
    c.signForm(form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  endl();

  std::cout << form << std::endl;
  endl();

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
  b.signForm(form);
  std::cout << form << std::endl;
}
