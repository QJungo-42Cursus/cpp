#include "Intern.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern(){}
Intern::Intern(Intern const &src){}
Intern::~Intern(){}

Intern &Intern::operator=(Intern const &rhs)
{
	return *this;
}

Form *Intern::makeForm(std::string const &form_name, std::string const &target) const
{
	if (form_name == "robotomy request") {
		return new RobotomyRequestForm(target);
	} else if (form_name == "shrubbery creation") {
		return new ShrubberyCreationForm(target);
	} else if (form_name == "presidential pardon") {
		return new PresidentialPardonForm(target);
	} else {
		throw UnexistingFormNameException();
	}
}