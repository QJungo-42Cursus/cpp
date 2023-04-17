#include "Bureaucrat.h"
#include "Form.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

void endl() { std::cout << std::endl; }

void test1()
{
  ShrubberyCreationForm *form = new ShrubberyCreationForm("shrub");
  Bureaucrat c("Cindy", 150);
  try
  {
    c.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  std::cout << c << std::endl;
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
  try
  {
    b.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  endl();

  try
  {
    c.executeForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  try
  {
    b.executeForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  delete form;
}

void test2()
{
  PresidentialPardonForm *form = new PresidentialPardonForm("president");
  Bureaucrat c("Cindy", 150);
  try
  {
    c.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  std::cout << c << std::endl;
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
  try
  {
    b.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  endl();

  try
  {
    c.executeForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    b.executeForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  delete form;
}

void test3()
{
  RobotomyRequestForm *form = new RobotomyRequestForm("robot");
  Bureaucrat c("Cindy", 150);
  try
  {
    c.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  std::cout << c << std::endl;
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
  try
  {
    b.signForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << *form << std::endl;
  endl();

  try
  {
    c.executeForm(*form);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  for (int i = 0; i < 10; i++)
  {
    try
    {
      b.executeForm(*form);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  delete form;
}

int main()
{
  test1();
  endl();
  endl();
  endl();
  test2();
  endl();
  endl();
  endl();
  test3();
  return 0;
}