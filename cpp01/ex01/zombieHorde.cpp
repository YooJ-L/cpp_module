#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	Zombie	*zombies;

	zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		zombies[i].setName(name + std::to_string(i));
	}
	return zombies;
}