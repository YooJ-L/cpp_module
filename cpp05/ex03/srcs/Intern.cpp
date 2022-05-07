#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	static_cast<void>(other);
}

Intern::~Intern() {}

Intern& Intern::operator =(const Intern &other)
{
	static_cast<void>(other);
	return *this;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	try {
		for (int i = 0; i < 3; i++)
		{
			if (forms[i] == formName)
			{
				switch (i) {
					case 0:
						return (createShrubberyForm(target));
					case 1:
						return (createRobotomyForm(target));
					case 2:
						return (createPresidentialForm(target));
					default:
						break ;
				}
			}
		}
		throw (NoMatchingFormNameException());
	} catch (const std::exception &e) {
		std::cout << "[ Intern ] " << e.what() << std::endl;
	}
	return (NULL);
}

Form *Intern::createShrubberyForm(const std::string &target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return (new ShrubberyCreationForm(target));
}

Form *Intern::createRobotomyForm(const std::string &target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(target));
}

Form *Intern::createPresidentialForm(const std::string &target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(target));
}

//exception
const char *Intern::NoMatchingFormNameException::what() const throw()
{
	return ("ERROR: Cannot find matching form");
}