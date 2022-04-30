#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	_name = name;
} //_weapon 클래스 변수는 참조 변수라서 생성자 리스트를 통해 초기화

HumanA::~HumanA()
{
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl;
}