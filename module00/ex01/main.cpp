#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	task;
	
	std::cout << "Enter a command (ADD or SEARCH or EXIT): ";
	while (std::getline(std::cin, task))
	{
		if (task == "ADD" || task == "add")
		{
			phonebook.AddContact();
		}
		else if (task == "SEARCH" || task == "search")
		{
			phonebook.SearchContact();
		}
		else if (task == "EXIT" || task == "exit")
		{
			std::cout << "break\n";
			break ;
		}
		std::cout << "Enter a command (ADD or SEARCH or EXIT): ";
	}
	return (0);
}