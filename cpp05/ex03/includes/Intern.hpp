#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <iostream>

class	Intern
{
	private:
		Form *createShrubberyForm(const std::string &target);
		Form *createRobotomyForm(const std::string &target);
		Form *createPresidentialForm(const std::string &target);

		class NoMatchingFormNameException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern& operator =(const Intern &other);
		
		Form	*makeForm(const std::string &formName, const std::string &target);
};

#endif