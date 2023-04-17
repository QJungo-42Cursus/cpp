#include "PresidentialPardonForm.h"

/* Constructors and destructor */
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", defaultGradeToSign, defaultGradeToExecute)
{
  this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : Form(other)
{
  this->_target = other._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Overload Operators */
PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
  if (this != &rhs)
  {
    this->_target = rhs._target;
  }
  return *this;
}

/* Methods */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  if (!this->getIsSigned())
  {
    throw NotSignedException();
  }
  if (this->getGradeToExecute() < executor.getGrade())
  {
    throw GradeTooLowException();
  }
  std::cout << _target << " received the pardon and salutation from Zaphod Beeblebrox" << std::endl;
}