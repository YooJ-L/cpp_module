#include "Zombie.hpp"

int	main(void)
{
	std::cout << "===Heap===" << std::endl;
	Zombie *zombie1;
	Zombie *zombie2;

	zombie1 = newZombie("zombie1");
	zombie2 = newZombie("zombie2");
	zombie1->announce();
	zombie2->announce();

	std::cout << "\n===Stack===" << std::endl;
	Zombie zom1("zom1");
	Zombie zom2("zom2");

	zom1.announce();
	zom2.announce();

	std::cout << "\n===RandomChump===" << std::endl;
	randomChump("RandomZombie1");
	randomChump("RandomZombie2");

	delete zombie1;
	delete zombie2;
	return (0);
}