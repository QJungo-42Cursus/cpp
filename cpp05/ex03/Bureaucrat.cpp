#include "Bureaucrat.h"

/* Constructors and Destructors */
Bureaucrat::Bureaucrat() : _name("has_no_name"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _name(name)
{
  if (grade < HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  if (grade > LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

/* Getters */
const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

/* Modifiers */
void Bureaucrat::incrementGrade()
{
  if (_grade == HIGHEST_GRADE)
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade()
{
  if (_grade == LOWEST_GRADE)
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

/* Methods */
void Bureaucrat::signForm(Form &form) const
{
  try
  {
    form.beSigned(*this);
    std::cout << _name << " signed Form \"" << form.getName() << "\""
              << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << _name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(Form const &form)
{
  try
  {
    form.execute(*this);
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << this->getName() << " failed to executed "
              << form.getName() << " because " << e.what() << std::endl;
  }
}

/* Operators overloads */
std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
  os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
  return os;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
  if (this != &rhs)
  {
    this->_grade = rhs._grade;
  }
  return *this;
}