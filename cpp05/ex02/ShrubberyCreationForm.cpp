#include "ShrubberyCreationForm.h"

/* Constructors and destructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137) {
  this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other) {
  this->_target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Overload Operators */
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    this->_target = rhs._target;
  }
  return *this;
}

/* Methods */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw GradeTooHighException();
  }
  if (this->getGradeToExecute() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  // TODO do something
}