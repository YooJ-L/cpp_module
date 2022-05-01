#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon bobClub = Weapon("crude spiked club");
		
		HumanA bob("Bob", bobClub);
		bob.attack();
		bobClub.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << std::endl;
		Weapon jimClub = Weapon("crude spiked club");
		
		HumanB jim("Jim");
		jim.setWeapon(&jimClub);
		jim.attack();
		jimClub.setType("some other type of club");
		jim.attack();
	}
	return 0;
}