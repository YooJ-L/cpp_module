#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: Form("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: Form("ShrubberyCreation", 145, 137), _target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm &other)
{
	static_cast<void>(other);
	return *this;
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	std::ofstream	W_file(_target + "_shrubbery");
	if (W_file.fail())
		throw FileErrException();
	W_file << "                                                         . " << std::endl;
	W_file << "                                               .         ;   " << std::endl;
	W_file << "                  .              .              ;%     ;;    " << std::endl;
	W_file << "                    ,           ,                :;%  %;    " << std::endl;
	W_file << "                     :         ;                   :;%;'     .,    " << std::endl;
	W_file << "            ,.        %;     %;            ;        %;'    ,; " << std::endl;
	W_file << "              ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
	W_file << "               %;       %;%;      ,  ;       %;  ;%;   ,%;'  " << std::endl;
	W_file << "                ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
	W_file << "                 `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
	W_file << "                  `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
	W_file << "                     `:%;.  :;bd%;          %;@%;' " << std::endl;
	W_file << "                       `@%:.  :;%.         ;@@%;'    " << std::endl;
	W_file << "                         `@%.  `;@%.      ;@@%;          " << std::endl;
	W_file << "                           `@%%. `@%%    ;@@%;         " << std::endl;
	W_file << "                             ;@%. :@%%  %@@%;        " << std::endl;
	W_file << "                               %@bd%%%bd%%:;      " << std::endl;
	W_file << "                                 #@%%%%%:;; " << std::endl;
	W_file << "                                 %@@%%%::; " << std::endl;
	W_file << "                                 %@@@%(o);  . '          " << std::endl;
	W_file << "                                 %@@@o%;:(.,'          " << std::endl;
	W_file << "                             `.. %@@@o%::;          " << std::endl;
	W_file << "                                `)@@@o%::;          " << std::endl;
	W_file << "                                 %@@(o)::;         " << std::endl;
	W_file << "                                .%@@@@%::;          " << std::endl;
	W_file << "                                ;%@@@@%::;.           " << std::endl;
	W_file << "                               ;%@@@@%%:;;;.  " << std::endl;
	W_file << "                           ...;%@@@@@%%:;;;;,..    Gilo97 " << std::endl;
	W_file.close();
	std::cout << "[ ShuruberryCreationForm::execute SUCCESS ] [ " << this->getTarget() << " ] shrubbery is successfully made." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out	<< "# Form Name     : " << form.getFormName() << '\n' \
		<< "# Target        : " << form.getTarget() << '\n' \
		<< "# Status        : " << (form.getIsSigned() == true ? "Signed" : "Unsigned") << '\n' \
		<< "# Sign Grade    : " << form.getSignGrade() << '\n' \
		<< "# Execute Grade : " << form.getExecuteGrade() << std::endl;
	return (out);
}

//exception
const char *ShrubberyCreationForm::FileErrException::what() const throw()
{
	return ("ERROR: Cannot open the file");
}