#include "phonebook.hpp"

void	Phonebook::PrintCmd(void) {
	std::cout << "Choose one : ADD, SEARCH, EXIT\nType here: ";
}

std::string Phonebook::InputCmd(void) {
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	return (input);
}