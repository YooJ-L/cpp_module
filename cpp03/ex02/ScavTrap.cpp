#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Conversion constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& other)
{
	setName(other.getName());
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << std::endl;
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "[ ATTACK ] ScavTrap " << getName() << ": FAIL: NO ENERGY POINT or NO HIT POINT" << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "[ ATTACK ] " << "ScavTrap " << getName() << " attacks " << target << ", causing [ " << _attackDamage << " ] points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << std::endl;
	if (_hitPoint != 0)
		std::cout << "[ GUARDGATE ] ScavTrap "<< getName() << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "[ GUARDGATE ] ScavTrap " << getName() << ": FAIL: ScavTrap is dead. Cannot get in Gate keeper mode." << std::endl;
}
