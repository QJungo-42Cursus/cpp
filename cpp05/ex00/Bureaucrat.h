#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>

class Bureaucrat
{
public:
  /* Constructors and Destructors */
  Bureaucrat();
  Bureaucrat(std::string const &name, int grade);
  Bureaucrat(Bureaucrat const &src);
  ~Bureaucrat();

  /* Operators overloads */
  Bureaucrat &operator=(Bureaucrat const &rhs);

  /* getters */
  std::string const &getName() const;
  int getGrade() const;

  /* Modifiers */
  void incrementGrade();
  void decrementGrade();

  /* exceptions */
  struct GradeTooHighException : public std::exception
  {
    virtual const char *what() const throw() { return "Grade too high"; }
  };
  struct GradeTooLowException : public std::exception
  {
    virtual const char *what() const throw() { return "Grade too low"; }
  };

  static const int LOWEST_GRADE = 150;
  static const int HIGHEST_GRADE = 1;

private:
  /* data members */
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif /* BUREAUCRAT_H */
