#include "ScavTrap.hpp"

int		main(void)
{
	ScavTrap	ScavA("ScavA");
	ScavTrap	ScavB("ScavB");
	ScavTrap	ScavC("ScavC");

	std::cout << std::endl;
	ScavA.attack("ScavB");
	ScavB.takeDamage(ScavA.getAttackDamagePoint());

	std::cout << std::endl;
	ScavB.attack("ScavA");
	ScavA.takeDamage(ScavB.getAttackDamagePoint());

	std::cout << std::endl;
	ScavC.attack("ScavB");
	ScavB.takeDamage(ScavC.getAttackDamagePoint());

	std::cout << std::endl;
	ScavA.beRepaired(25);

	std::cout << std::endl;

	ScavA.guardGate();
	ScavB.guardGate();
	ScavC.guardGate();

	std::cout << std::endl;
	return (0);
}