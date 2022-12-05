#include "Form.h"
#include "Bureaucrat.h"

/* Constructors and destructor */
Form::Form(std::string const &name, int const gradeToSign,
           int const gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
  _signed = false;
}

Form::~Form() {}

/* Getters */
std::string const &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

/* Setters */
void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign) {
    throw Form::GradeTooLowException();
  }
  _signed = true;
}
