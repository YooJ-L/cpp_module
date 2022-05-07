#include "../includes/Form.hpp"

Form::Form()
: _name("default"), _signGrade(150), _executeGrade(150)
{
	_isSigned = false;
}

Form::Form(const std::string &formName, const int signGrade, const int executeGrade)
: _name(formName), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || executeGrade > 150)
	{
		throw GradeTooLowException();
	}
	_isSigned = false;
}

Form::Form(const Form &other)
: _name(other.getFormName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	_isSigned = other._isSigned;
	*this = other; //써주는 사람도 있고 안써주는 사람도 있던데 무슨 차이?
}

Form::~Form()
{
}

Form& Form::operator =(const Form& other)
{
	_isSigned = other._isSigned;
	return *this;
}

int		Form::getSignGrade() const
{
	return _signGrade;
}

int		Form::getExecuteGrade() const
{
	return _executeGrade;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned == false)
	{
		if (bureaucrat.getGrade() > this->_signGrade)
		{
			std::cout << "**" << bureaucrat.getName() << "**" << " couldn't sign " << "**" << this->_name << "**" << " because ";
			throw GradeTooLowException();
		}
		_isSigned = true;
	}
	else
		std::cout << "**" << this->_name << "**" << " is signed already." << std::endl;
}

std::ostream& operator <<(std::ostream &out, const Form &form)
{
	out << "# Form			: " << form.getFormName() << std::endl;
	out << "# Status		: " << (form.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	out << "# Sign Grade		: " << form.getSignGrade() << std::endl;
	out << "# Execute Grade		: " << form.getExecuteGrade() << std::endl;
	return (out);
}

//exception
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Is Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Is Too Low");
}

const std::string& Form::getFormName() const
{
	return _name;
}