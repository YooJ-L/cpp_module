#include "../includes/Bureaucrat.hpp"

int		main(void)
{
	try {
		std::cout << "===== =====" << std::endl;

		Bureaucrat person1("person1", 1);
		Bureaucrat person2("person2", 100);
		Bureaucrat copy(person1);

		std::cout << person1 << std::endl;
		std::cout << copy << std::endl;
		std::cout << person2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== Too High Case =====" << std::endl;

		Bureaucrat person3("person3", 0);
		std::cout << person3 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== Too Low Case =====" << std::endl;

		Bureaucrat person4("person4", 151);
		std::cout << person4 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== Increment Test =====" << std::endl;

		Bureaucrat person5("person5", 2);
		std::cout << person5 << std::endl;
		person5.increaseGrade();
		std::cout << person5 << std::endl;
		person5.increaseGrade();
		std::cout << person5 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "\n===== Decrement Test =====" << std::endl;

		Bureaucrat person6("person6", 149);
		std::cout << person6 << std::endl;
		person6.decreaseGrade();
		std::cout << person6 << std::endl;
		person6.decreaseGrade();
		std::cout << person6 << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}