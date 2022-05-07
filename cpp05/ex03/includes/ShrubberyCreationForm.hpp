#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	private:
		const std::string	_target;

		class FileErrException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator =(const ShrubberyCreationForm &other);

		virtual const std::string&	getTarget() const;

		virtual void	execute(const Bureaucrat &executor) const;
};

std::ostream&	operator <<(std::ostream &out, const ShrubberyCreationForm& form);

#endif