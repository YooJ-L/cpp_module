#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int		main(void)
{
	Bureaucrat bu("bu", 150);
	Bureaucrat re("re", 140);
	Bureaucrat au("au", 100);
	Bureaucrat cr("cr", 50);
	Bureaucrat at("at", 5);
	Form *forms[3] = {  new ShrubberyCreationForm("Shru"),
						new RobotomyRequestForm("Robo"),
						new PresidentialPardonForm("Pres") };
	std::cout << bu << '\n'
	          << re << '\n'
	          << au << '\n'
	          << cr << '\n'
	          << at << '\n'
	          << std::endl;

	std::cout << "[ No Sign Error Test ]\n\n";
	for (int i = 0; i < 3; i++) {
	  bu.executeForm(*forms[i]);
	  re.executeForm(*forms[i]);
	  au.executeForm(*forms[i]);
	  cr.executeForm(*forms[i]);
	  at.executeForm(*forms[i]);
	  std::cout << '\n';
	}

	std::cout << "\n[ Sign Test ]\n\n";
	for (int i = 0; i < 3; i++) {
	  bu.signForm(*forms[i]);
	  std::cout << '\n';
	  re.signForm(*forms[i]);
	  std::cout << '\n';
	  au.signForm(*forms[i]);
	  std::cout << '\n';
	  cr.signForm(*forms[i]);
	  std::cout << '\n';
	  at.signForm(*forms[i]);
	  std::cout << "\n---\n";
	}   
	std::cout << "\n[ Exec Test ]\n\n";
	for (int i = 0; i < 3; i++) {
	  bu.executeForm(*forms[i]);
	  re.executeForm(*forms[i]);
	  au.executeForm(*forms[i]);
	  cr.executeForm(*forms[i]);
	  at.executeForm(*forms[i]);
	  std::cout << '\n';
	}
	for (int i = 0; i < 3; i++) {
	  delete forms[i];
	}
}