#include "Form.h"
#include "Bureaucrat.h"

/* Constructors and destructor */
Form::Form()
    : _name("default"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(std::string const &name, int const gradeToSign,
           int const gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
  if (gradeToSign < Bureaucrat::HIGHEST_GRADE || gradeToExecute < Bureaucrat::HIGHEST_GRADE)
  {
    throw Form::GradeTooHighException();
  }
  else if (gradeToSign > Bureaucrat::LOWEST_GRADE || gradeToExecute > Bureaucrat::LOWEST_GRADE)
  {
    throw Form::GradeTooLowException();
  }
}

Form::Form(Form const &src)
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute) {}

Form::~Form() {}

/* Operators overloads */
Form &Form::operator=(Form const &rhs) {
  if (this != &rhs) {
    _signed = rhs._signed; // c'est le seul qui n'est pas const
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
  o << "Form \"" << rhs.getName() << "\" is "
    << (rhs.getIsSigned() ? "signed" : "not signed");
  return o;
}

/* Getters */
std::string const &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
const std::string &Form::getTarget() const { return _target; }

/* Setters */
void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign) {
    throw Form::GradeTooLowException();
  }
  _signed = true;
}
