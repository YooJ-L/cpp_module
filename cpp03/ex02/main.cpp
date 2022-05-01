#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap	Aa("Aa");
	ScavTrap	Bb("Bb");

	std::cout << std::endl;
	Aa.attack("Bb");
	Bb.takeDamage(Aa.getAttackDamagePoint());

	std::cout << std::endl;
	Bb.attack("Aa");
	Aa.takeDamage(Bb.getAttackDamagePoint());

	std::cout << std::endl;
	Aa.attack("Bb");
	Bb.takeDamage(Aa.getAttackDamagePoint());

	std::cout << std::endl;
	Bb.attack("Aa");
	Aa.takeDamage(Bb.getAttackDamagePoint());

	std::cout << std::endl;
	Aa.attack("Bb");
	Bb.takeDamage(Aa.getAttackDamagePoint());

	std::cout << std::endl;
	Aa.attack("Bb");
	Bb.takeDamage(Aa.getAttackDamagePoint());

	std::cout << std::endl;
	Aa.attack("Bb");
	Bb.takeDamage(Aa.getAttackDamagePoint());

	std::cout << std::endl;
	Bb.guardGate();

	std::cout << std::endl;
	Aa.highFivesGuys();

	std::cout << std::endl;
	return (0);
}