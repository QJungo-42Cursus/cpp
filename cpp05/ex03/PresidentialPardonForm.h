#ifndef PresidentialPardonForm_H
#define PresidentialPardonForm_H
#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

class PresidentialPardonForm : public Form {
public:
  /* Constructors and destructor */
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  virtual ~PresidentialPardonForm();

  /* Overload Operators */
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  /* methods */
  void execute(Bureaucrat const &executor) const;

  static const int defaultGradeToSign = 25;
  static const int defaultGradeToExecute = 5;

private:
  PresidentialPardonForm();
};

#endif /* PresidentialPardonForm_H */
