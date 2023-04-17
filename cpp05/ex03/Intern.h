#ifndef INTERN_H
#define INTERN_H
#include "Form.h"
#include <iostream>

class Intern {
public:
  /* Constructors and Destructors */
  Intern();
  Intern(Intern const &src);
  ~Intern();

  /* Operators overloads */
  Intern &operator=(Intern const &rhs);

  /* Methods */
  Form *makeForm(std::string const &form_name, std::string const &target) const;

  /* exceptions */
  struct UnexistingFormNameException : public std::exception {
    virtual const char *what() const throw() { return "This form name's doesn't exist"; }
  };
};

#endif /* Intern_H */
