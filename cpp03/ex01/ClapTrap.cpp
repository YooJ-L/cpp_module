#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("anonymous"),
  _hitPoint(10),
  _energyPoint(10),
  _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name),
 _hitPoint(10),
 _energyPoint(10),
 _attackDamage(0)
{
	std::cout << "ClapTrap Conversion constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: _name(other._name),
 _hitPoint(other._hitPoint),
 _energyPoint(other._energyPoint),
 _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap &other)
{
	_name = other._name;
	_hitPoint = other._hitPoint;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << std::endl;
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "[ ATTACK ] ClapTrap " << this->_name << ": FAIL: NO ENERGY POINT or NO HIT POINT" << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "[ ATTACK ] " << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl;
	std::cout << "[ TAKE DAMAGE ] ";
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead.." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has taken [ " << amount << " ] amount of damage..!+!!+!" << std::endl;
	if (_hitPoint <= amount)
	{
		_hitPoint = 0;
		std::cout << "		=> [ 0 ] hit points left. He's dead.." << std::endl;
	}
	else
	{
		_hitPoint -= amount;
		std::cout << "		=> [ " << _hitPoint << " ] hit points left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl;
	std::cout << "[ REPAIRED ]";
	if (_hitPoint != 0 && _energyPoint != 0)
	{
		_hitPoint += amount;
		_energyPoint--;
		std::cout << "ClapTrap " << _name << " got back [ " 
			<< amount << " ] hit points and lose 1 energy point.\n		=> [ " << _energyPoint << " ] energy points left." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << ": FAIL: NO ENERGY POINT or NO HIT POINT" << std::endl;
	}
}

unsigned int		ClapTrap::getAttackDamagePoint(void) const
{
	return (_attackDamage);
}

unsigned int		ClapTrap::getHitPoint(void) const
{
	return (_hitPoint);
}

unsigned int		ClapTrap::getEnergyPoint(void) const
{
	return (_energyPoint);
}

std::string	const&	ClapTrap::getName(void) const
{
	return (_name);
}

void				ClapTrap::setName(const std::string& name)
{
	_name = name;
}