#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
		const std::string	_target;

		class RobotomizeFailException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator =(const RobotomyRequestForm &other);

		virtual const std::string&	getTarget() const;

		virtual void	execute(const Bureaucrat &executor) const;
};

std::ostream& operator <<(std::ostream &out, const RobotomyRequestForm& form);

#endif