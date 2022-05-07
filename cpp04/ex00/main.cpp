#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int		main(void)
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl;
	
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;
	system("leaks polymorphism");
	return 0;
}
