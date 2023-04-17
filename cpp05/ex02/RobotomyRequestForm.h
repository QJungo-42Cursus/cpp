#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

class ShrubberyCreationForm : public Form {
public:
  /* Constructors and destructor */
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  virtual ~ShrubberyCreationForm();

  /* Overload Operators */
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  /* methods */
  void execute(Bureaucrat const &executor) const;

private:
  ShrubberyCreationForm();
};

#endif /* SHRUBBERYCREATIONFORM_H */
