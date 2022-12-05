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

  /* Methods */
  // void signForm(Form &form);

private:
  /* data members */
  std::string const _name;
  int _grade;

  /**/
  enum Grade { LOWEST = 150, HIGHEST = 1 };

  /* exceptions */
  struct GradeTooHighException {};
  struct GradeTooLowException {};
};

#endif /* BUREAUCRAT_H */
