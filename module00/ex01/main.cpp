#include "phonebook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	while(1) {
		phonebook.PrintCmd();
		input = phonebook.InputCmd();
		switch (phonebook.CmdType) {

		}
	}
}