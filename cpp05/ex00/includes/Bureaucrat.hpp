#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

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

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator =(const Bureaucrat &other);

		const std::string&	getName() const;
		int					getGrade() const;

		void	increaseGrade();
		void	decreaseGrade();
};

std::ostream& operator <<(std::ostream &out, const Bureaucrat &obj);



#endif