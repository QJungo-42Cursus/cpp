#include "ShrubberyCreationForm.h"
#include <fstream>

/* Constructors and destructor */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", defaultGradeToSign, defaultGradeToExecute)
{
  this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(other)
{
  this->_target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Overload Operators */
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
  if (this != &rhs)
  {
    this->_target = rhs._target;
  }
  return *this;
}

/* Methods */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  if (!this->getIsSigned())
  {
    throw NotSignedException();
  }
  if (this->getGradeToExecute() < executor.getGrade())
  {
    throw GradeTooLowException();
  }
  std::string filename = getName() + "_shrubbery";
  std::ofstream new_file;
  new_file.open(filename, std::ios::out);
  if (!new_file.good())
  {
    std::cerr << "Error creating file " << filename << std::endl;
    exit(1);
  }
  if (!new_file.is_open())
  {
    std::cerr << "Error opening file " << filename << std::endl;
    exit(1);
  }
  new_file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\";
  new_file.close();
}