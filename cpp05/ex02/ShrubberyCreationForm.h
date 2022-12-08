#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "Form.h"
#include <iostream>

class ShrubberyCreationForm : public Form {
public:
  /* Constructors and destructor */
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  virtual ~ShrubberyCreationForm();

  /* Overload Operators */
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  /* */

private:
};

#endif /* SHRUBBERYCREATIONFORM_H */
