#include "RobotomyRequestForm.h"

/* Constructors and destructor */
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 145, 137) {
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other) {
  this->_target = other._target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/* Overload Operators */
RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    this->_target = rhs._target;
  }
  return *this;
}

/* Methods */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->getIsSigned()) {
    throw GradeTooHighException();
  }
  if (this->getGradeToExecute() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  // TODO do something
}