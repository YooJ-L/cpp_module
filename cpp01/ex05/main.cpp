#include "Harl.hpp"

int		main(void)
{
	Harl	harl;

	std::cout << "===DEBUG===" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n===INFO===" << std::endl;
	harl.complain("INFO");

	std::cout << "\n===WARNING===" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n===ERROR===" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n===LowerCase" << std::endl;
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");

	std::cout << "\n===xxx===" << std::endl;
	harl.complain("abc");
	harl.complain("");

	return (0);
}