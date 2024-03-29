#ifndef RobotomyRequestForm_H
#define RobotomyRequestForm_H
#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

class RobotomyRequestForm : public Form {
public:
  /* Constructors and destructor */
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  virtual ~RobotomyRequestForm();

  /* Overload Operators */
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  /* methods */
  void execute(Bureaucrat const &executor) const;

  static const int defaultGradeToSign = 72;
  static const int defaultGradeToExecute = 45;

private:
  RobotomyRequestForm();
};

#endif /* RobotomyRequestForm_H */
