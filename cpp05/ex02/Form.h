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
  virtual ~Form();

  /* Operators overloads */
  Form &operator=(Form const &rhs);

  /* Getters */
  const std::string &getName() const;
  const std::string &getTarget() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  /* Setters */
  virtual void beSigned(Bureaucrat const &bureaucrat);

  /* Methods */
  virtual void execute(Bureaucrat const &executor) const = 0;

  /* exceptions */
  struct GradeTooHighException : public std::exception {
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  struct GradeTooLowException : public std::exception {
    virtual const char *what() const throw() { return "Grade too low"; }
  };

protected:
  const std::string _name;
  const int _gradeToSign;
  const int _gradeToExecute;
  bool _signed;

  const std::string _target;
};

/* Operators overloads */
std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif /* FORM_H */
