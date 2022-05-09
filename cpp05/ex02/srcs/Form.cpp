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
	*this = other;
}

Form::~Form()
{
}

Form& Form::operator =(const Form& other)
{
	_isSigned = other._isSigned;
	return *this;
}

const std::string& Form::getFormName() const
{
	return _name;
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
			std::cout << "** " << bureaucrat.getName() << " ** couldn't sign " << "[ " << this->_name << " ] because ";
			throw GradeTooLowException();
		}
		_isSigned = true;
	}
	else
		std::cout << "[ " << this->_name << " ] is signed already." << std::endl;
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
	{
		throw NotSignedException();
	}
	if (_executeGrade < executor.getGrade())
	{
		std::cout << "[ Form::execute FAIL ] ** " << executor.getName() << " **" << " couldn't execute " \
					<< "[ " << this->getFormName() << " ]" << " because ";
		throw ExecGradeTooLowException();
	}
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
	return ("ERROR: Grade Is Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade Is Too Low");
}

const char *Form::FormIsAlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

const char *Form::NotSignedException::what() const throw()
{
	return ("ERROR: Form need to be signed");
}

const char *Form::ExecGradeTooLowException::what() const throw()
{
	return ("ERROR: Grade is too low to execute the form");
}
