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
			// private:
				// int	grade; //이건?
			public:
				// GradeTooHighException(); //이건?
				const char *what() const throw(); //virtual 이어야 하는 이유는?

		};
		class GradeTooLowException : public std::exception
		{
			private:
				// int grade;
			
			public:
				// GradeTooLowException();
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