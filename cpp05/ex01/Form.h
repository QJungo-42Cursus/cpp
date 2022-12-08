#ifndef FORM_H
#define FORM_H
#include <iostream>

class Bureaucrat;

class Form {
public:
  /* Constructors and destructor */
  Form();
  Form(std::string const &name, int const gradeToSign,
       int const gradeToExecute);
  Form(Form const &src);
  ~Form();

  /* Operators overloads */
  Form &operator=(Form const &rhs);

  /* Getters */
  std::string const &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  /* Setters */
  void beSigned(Bureaucrat const &bureaucrat);

  /* exceptions */
  struct GradeTooHighException : public std::exception {
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  struct GradeTooLowException : public std::exception {
    virtual const char *what() const throw() { return "Grade too low"; }
  };

private:
  const std::string _name;
  const int _gradeToSign;
  const int _gradeToExecute;
  bool _signed;
};

/* Operators overloads */
std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif /* FORM_H */
