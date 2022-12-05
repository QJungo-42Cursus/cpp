#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < Grade::HIGHEST)
    throw Bureaucrat::GradeTooHighException();
  if (grade > Grade::LOWEST)
    throw Bureaucrat::GradeTooLowException();
}

/* getters */
std::string const &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

/* Setters */
void Bureaucrat::incrementGrade() {
  if (_grade == Grade::HIGHEST)
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}
void Bureaucrat::decrementGrade() {
  if (_grade == Grade::LOWEST)
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

// TODO what doesen't work
std::ostream &Bureaucrat::operator<<(std::ostream &os) {
  os << this->getName() << ", bureaucrat grade " << this->getGrade()
     << std::endl;
  return os;
}
