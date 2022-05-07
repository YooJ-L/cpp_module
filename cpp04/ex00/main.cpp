#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int		main(void)
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* meta2 = new Animal("WhichAnimal?");
	std::cout << std::endl;
	Animal meta3;
	std::cout << std::endl;
	Animal meta4(meta3);
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	Dog dog1;
	std::cout << std::endl;
	Dog dog2(dog1);
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	Cat cat1;
	std::cout << std::endl;
	Cat cat2(cat1);
	std::cout << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << meta3.getType() << " " << std::endl;
	std::cout << meta4.getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << dog1.getType() << " " << std::endl;
	std::cout << dog2.getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << cat1.getType() << " " << std::endl;
	std::cout << cat2.getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << std::endl;
	
	meta->makeSound();
	meta2->makeSound();
	meta3.makeSound();
	meta4.makeSound();
	j->makeSound();
	dog1.makeSound();
	dog2.makeSound();
	i->makeSound();
	cat1.makeSound();
	cat2.makeSound();
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;
	system("leaks polymorphism");

	return 0;
}
