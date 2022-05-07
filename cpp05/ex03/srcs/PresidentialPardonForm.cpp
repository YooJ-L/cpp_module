#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: Form("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: Form("PresidentialPardon", 25, 5), _target(other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm &other)
{
	static_cast<void>(other); //여기서 안써줘서 void로
	return *this;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return _target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor); //부모클래스form안에 있는 execute함수를 쓰려고
	std::cout << "[ PresidentialPardonForm::execute SUCCESS ] [ " << this->getTarget() << " ] has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	out	<< "# Form Name     : " << form.getFormName() << '\n' \
		<< "# Target        : " << form.getTarget() << '\n' \
		<< "# Status        : " << (form.getIsSigned() == true ? "Signed" : "Unsigned") << '\n' \
		<< "# Sign Grade    : " << form.getSignGrade() << '\n' \
		<< "# Execute Grade : " << form.getExecuteGrade() << std::endl;
	return (out);
}