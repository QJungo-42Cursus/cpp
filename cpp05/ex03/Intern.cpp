#include "Intern.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern() {}
Intern::Intern(Intern const &src) 
{
	(void)src;
}
Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
	if (this != &rhs) 
	{
		return *this;
	}
	return *this;
}

struct Map
{
	std::string name;
	Form *form;
};

Form *Intern::makeForm(std::string const &form_name, std::string const &target) const
{
	Map forms[] = {
		{"robotomy request", new RobotomyRequestForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i].name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			int j = i + 1;
			while (j < 3)
			{
				delete forms[j].form;
				j++;
			}
			return forms[i].form;
		}
		else
		{
			delete forms[i].form;
		}
	}
	throw UnexistingFormNameException();
}