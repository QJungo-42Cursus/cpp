#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
public:
  /* Constructors and Destructors */
  Bureaucrat(std::string const &name, int grade);

  /* getters */
  std::string const &getName() const;
  int getGrade() const;

  /* Setters */
  void incrementGrade();
  void decrementGrade();

  std::ostream &operator<<(std::ostream &os);
private:
  /* data members */
  std::string const _name;
  int _grade;

  /**/
  enum Grade { LOWEST = 150, HIGHEST = 1 };

  /* exceptions */
  struct GradeTooHighException : public std::exception {
    const char *what() const throw() { return "Grade too high"; }
  };
  struct GradeTooLowException : public std::exception {
    const char *what() const throw() { return "Grade too low"; }
  };
};

#endif /* BUREAUCRAT_H */
