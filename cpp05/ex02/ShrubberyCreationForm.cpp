#include "ShrubberyCreationForm.h"

/* Constructors and destructor */
ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137) {
  this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form("ShrubberyCreationForm", 145, 137) {
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

/* Getters */
const std::string &ShrubberyCreationForm::getTarget() const {
  return this->_target;
}

/* Setters */
void ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > this->getGradeToSign()) {
    throw Form::GradeTooLowException();
  } else {
    this->_signed = true;
  }
}

/* Methods */
