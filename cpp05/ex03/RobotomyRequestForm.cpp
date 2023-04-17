#include "RobotomyRequestForm.h"

/* Constructors and destructor */
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", defaultGradeToSign, defaultGradeToExecute)
{
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other)
{
  this->_target = other._target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Overload Operators */
RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
  if (this != &rhs)
  {
    this->_target = rhs._target;
  }
  return *this;
}

#include <cstdlib>

/* Methods */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  if (!this->getIsSigned())
  {
    throw NotSignedException();
  }
  if (this->getGradeToExecute() < executor.getGrade())
  {
    throw GradeTooLowException();
  }
  std::cout << "[Bruits de perceuse...]" << std::endl;
  if (rand() % 2)
  {
    std::cout << _target << " was robotomised." << std::endl;
  }
  else
  {
    std::cout << _target << " failed to be robotomised !" << std::endl;
  }
}