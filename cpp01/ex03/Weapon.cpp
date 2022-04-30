#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const	std::string	&Weapon::getType()
{
	return _type; //클래스 변수 type의 참조를 반환
}