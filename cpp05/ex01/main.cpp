#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int		main(void)
{
	std::cout << "===== Constructor Error Test =====" << std::endl;
	try {
		Form form1("form1", 0, 0);
		Form form2("form2", 151, 151);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Main Test =====" << std::endl;

	Bureaucrat	person1("Tom", 10);
	Form		form1("Form1", 9, 9);
	Form		form2("Form2", 15, 15);

	std::cout << person1 << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== Start Test =====" << std::endl;

	try {
		person1.signForm(form1);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form1 << std::endl;

	try {
		person1.signForm(form2);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form2 << std::endl;

	try {
		person1.increaseGrade();
		person1.increaseGrade();
		person1.increaseGrade();
		person1.signForm(form1);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << form1 << std::endl;
}