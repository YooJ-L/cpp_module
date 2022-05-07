#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormIsAlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExecGradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		Form();
		Form(const std::string &formName, const int signGrade, const int executeGrade);
		Form(const Form &other);
		virtual ~Form();

		Form& operator =(const Form &other);

		const std::string&	getFormName() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		bool				getIsSigned() const;

		void	beSigned(const Bureaucrat &bureaucrat);

		virtual const std::string& getTarget() const = 0;

		virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream& operator <<(std::ostream &out, const Form &form);

#endif