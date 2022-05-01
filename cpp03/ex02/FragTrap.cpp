#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Conversion constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	setName(other.getName());
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << std::endl;
	std::cout << "[ highFivesGuys ]";
	if (_hitPoint != 0)
		std::cout << " FragTrap " << getName() << " request a positive high five." << std::endl;
	else
	{
		std::cout << " FragTrap " << getName() << ": FAIL: FragTrap is dead. Cannot request a positive high five." << std::endl;
	}
}