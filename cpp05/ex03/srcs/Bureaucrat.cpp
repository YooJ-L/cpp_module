#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("Anonymous"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name)
{
	if (grade < 1 || grade > 150)
		grade < 1 ? throw GradeTooHighException() : throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other.getName()), _grade(other.getGrade())
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat &other)
{
	// this->_name = other.getName(); //const 라서 재할당? 안되지 않나?
	this->_grade = other.getGrade();
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try {
		if (form.getIsSigned() == true)
			std::cout << "[ " << form.getFormName() << " ] is signed already" << std::endl;
		else
		{
			form.beSigned(*this);
			std::cout << "** " << this->getName() << " ** signed " << "[ " << form.getFormName() << " ]" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try {
		form.execute(*this);
		std::cout << "** " << this->_name << " ** executed " << "[ " << form.getFormName() << " ]" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator <<(std::ostream &out, const Bureaucrat &obj)
{
	out << "** " << obj.getName() << " **, bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}

//exception
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ERROR: TOO HIGH GRADE");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ERROR: TOO LOW GRADE");
}