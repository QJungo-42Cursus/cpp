#ifndef FORM_H
#define FORM_H
#include "common.h"
#include <iostream>

class Form {
public:
  /* Constructors and destructor */
  Form(std::string const &name, int const gradeToSign,
       int const gradeToExecute);
  ~Form();

  /* Getters */
  std::string const &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  /* Setters */
  void beSigned(Bureaucrat const &bureaucrat);

private:
  /* Data */
  std::string const _name;
  bool _signed;
  int const _gradeToSign;
  int const _gradeToExecute;

  /* Exceptions */
  // TODO find a way to share exceptions between classes
  struct iGradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  struct iGradeTooLowException : public std::exception {
    const char *what() const throw();
  };
};
#endif /* FORM_H */
