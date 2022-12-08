#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include "Form.h"
#include <iostream>

class Bureaucrat {
public:
  /* Constructors and Destructors */
  Bureaucrat();
  Bureaucrat(std::string const &name, int grade);
  Bureaucrat(Bureaucrat const &src);
  ~Bureaucrat();

  /* Operators overloads */
  Bureaucrat &operator=(Bureaucrat const &rhs);

  /* getters */
  const std::string &getName() const;
  int getGrade() const;

  /* Modifiers */
  void incrementGrade();
  void decrementGrade();

  /* Methods */
  void signForm(Form &form) const;

  /* exceptions */
  struct GradeTooHighException : public std::exception {
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  struct GradeTooLowException : public std::exception {
    virtual const char *what() const throw() { return "Grade too low"; }
  };

private:
  /* data members */
  const std::string _name;
  int _grade;

  /* Enums */
  enum Grade { LOWEST = 150, HIGHEST = 1 };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif /* BUREAUCRAT_H */
