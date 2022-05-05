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
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
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
		// throw GradeTooHighException(this->getGrade() - 1);
	else
		_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
		// throw GradeTooLowException(this->getGrade() + 1);
	else
		_grade++;
}

std::ostream& operator <<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ERROR: TOO HIGH GRADE");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ERROR: TOO LOW GRADE");
}