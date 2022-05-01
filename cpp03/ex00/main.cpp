#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	ClapA("ClapA");
	ClapTrap	ClapB("ClapB");
	ClapTrap	ClapC("ClapC");

	std::cout << std::endl;
	ClapA.attack("ClapB");
	ClapB.takeDamage(ClapA.getAttackDamagePoint());

	std::cout << std::endl;
	ClapB.attack("ClapA");
	ClapA.takeDamage(ClapB.getAttackDamagePoint());

	std::cout << std::endl;
	ClapC.attack("ClapB");
	ClapB.takeDamage(ClapC.getAttackDamagePoint());

	std::cout << std::endl;
	ClapA.beRepaired(25);

	std::cout << std::endl;
	return (0);
}