#ifndef FORM_H
#define FORM_H
#include <iostream>

class Bureaucrat;

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
  struct GradeTooHighException {};
  struct GradeTooLowException {};
};
/*
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
*/

#endif /* FORM_H */
