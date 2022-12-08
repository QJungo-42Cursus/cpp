#include "Bureaucrat.h"

/* Constructors and Destructors */
Bureaucrat::Bureaucrat() : _name("has_no_name"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < Grade::HIGHEST)
    throw Bureaucrat::GradeTooHighException();
  if (grade > Grade::LOWEST)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

/* Getters */
const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

/* Modifiers */
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

/* Operators overloads */
std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs) {
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
  return os;
}
