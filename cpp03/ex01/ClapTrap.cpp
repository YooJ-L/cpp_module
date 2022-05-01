#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("anonymous"),
  _hitPoints(10),
  _energyPoints(10),
  _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name),
 _hitPoints(10),
 _energyPoints(10),
 _attackDamage(0)
{
	std::cout << "ClapTrap Conversion constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: _name(other._name),
 _hitPoints(other._hitPoints),
 _energyPoints(other._energyPoints),
 _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << "가 " << target << " 공격. Caused " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _energyPoints)
	{
		_energyPoints = 0;
		std::cout << "ClapTrap " << this->_name << " 사망." << std::endl;
	}
	else
	{
		_energyPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " 데미지 입었음." <<  "[ Energy Points : " << _energyPoints << " ]" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energyPoints)
	{
		_energyPoints = amount;
		std::cout << "ClapTrap " << this->_name << " 부활!" << "[ Energy Points : " << _energyPoints << " ]" << std::endl;
	}
	else
	{
		_energyPoints += amount;
		std::cout << "ClapTrap " << this->_name << " 에너지 보충.." << "[ Energy Points : " << _energyPoints << " ]" << std::endl;
	}
}

const std::string&	ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int		ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

unsigned int		ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

unsigned int		ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

