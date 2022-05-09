#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib> //srand
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequest", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: Form("RobotomyRequest", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form("RobotomyRequest", 72, 45), _target(other.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm &other)
{
	static_cast<void>(other);
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	std::cout << "@#$$#@#$!@#%~~~drilling noises~~~!#@$$#@$!!!#@$#$" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2)
		std::cout << "[ RobotomyRequestForm::execute SUCCESS ] [ " << this->getTarget() << " ] has been robotomized." << std::endl;
	else
	{
		std::cout << "**" << executor.getName() << "** " << "executed [ " << this->getFormName() << " ]\nBUT ";
		throw RobotomizeFailException();
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out	<< "# Form Name     : " << form.getFormName() << '\n' \
		<< "# Target        : " << form.getTarget() << '\n' \
		<< "# Status        : " << (form.getIsSigned() == true ? "Signed" : "Unsigned") << '\n' \
		<< "# Sign Grade    : " << form.getSignGrade() << '\n' \
		<< "# Execute Grade : " << form.getExecuteGrade() << std::endl;
	return (out);
}

//exception
const char *RobotomyRequestForm::RobotomizeFailException::what() const throw()
{
	return ("ERROR: Robotomize failed");
}