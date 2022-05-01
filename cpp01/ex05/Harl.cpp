#include "Harl.hpp"

Harl::Harl()
{
	_levels_fn[0].level = "DEBUG";
	_levels_fn[1].level = "INFO";
	_levels_fn[2].level = "WARNING";
	_levels_fn[3].level = "ERROR";
	_levels_fn[0].function = &Harl::debug;
	_levels_fn[1].function = &Harl::info;
	_levels_fn[2].function = &Harl::warning;
	_levels_fn[3].function = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	for (size_t idx = 0; idx < 4; idx++)
	{
		for (size_t i = 0; i < level.length(); i++)
		{
			level[i] = static_cast<char>(std::toupper(level[i]));
		}
		if (level == _levels_fn[idx].level)
		{
			(this->*_levels_fn[idx].function)();
			return ;
		}
	}
	std::cout << "There's no such level." << std::endl;
}